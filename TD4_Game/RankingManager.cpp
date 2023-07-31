#include "RankingManager.h"

#include <Raki_imguiMgr.h>

RankingManager::~RankingManager()
{
}

void RankingManager::Init()
{
    GetRanking();
}

void RankingManager::Update()
{

}


void RankingManager::Draw2D()
{
}

void RankingManager::DebugDraw()
{
    //imgui�Ń����L���O�f�[�^�\��

    ImguiMgr::Get()->StartDrawImgui("rankingdata", 100, 100);

    int i = 1;

    for (auto& r : rankingArray) {
        ImGui::Text("%d : %d", i, r);
        i++;
    }

    ImguiMgr::Get()->EndDrawImgui();
}


void RankingManager::PostScore(int score)
{

    if (!isRankingSend) {
        //�X�R�A���M
        try
        {
            auto serverStatusCode = Post(L"http://localhost:3000/hage_games/", score).wait();
            //����
            if (serverStatusCode == 1 || serverStatusCode == 2) {
                isRankingSend = true;
            }

        }
        catch (const std::exception& e)
        {
            std::cout << "RankingManager | Exception Detected : %s" << e.what() << std::endl;
        }
    }

}

std::array<int, 5> RankingManager::GetRanking()
{
    if (!isRankingGot) {
        //�X�R�A�擾
        try
        {
            auto task = Get<json::value>(L"http://localhost:3000/hage_games/");
            const json::value j = task.get();
            auto array = j.as_array();

            // JSON�I�u�W�F�N�g����K�v������؂�o����int�^�̔z��ɑ��
            for (int i = 0; i < array.size(); i++)
            {
                rankingArray[i] = array[i].at(U("score")).as_integer();
            }

            isRankingGot = true;
        }
        catch (const std::exception& e)
        {
            std::cout << "RankingManager | Exception Detected : %s" << e.what() << std::endl;
        }
    }

    return rankingArray;
}

template<class T>
pplx::task<T> RankingManager::Get(const std::wstring& url)
{
    return pplx::create_task([=]
        {
            http_client client(url);
    return client.request(methods::GET); })
        .then([](http_response response)
            {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } });
}

pplx::task<int> RankingManager::Post(const std::wstring& url, int score)
{
    return pplx::create_task([=]
        {
            json::value postData;
    postData[L"score"] = score;

    http_client client(url);
    return client.request(methods::POST, L"", postData.serialize(),
        L"application/json"); })
        .then([](http_response response)
            {
                if (response.status_code() == status_codes::OK) {
                    return response.extract_json();
                } })
        .then(
            [](json::value json)
            { return json[L"serverStatus"].as_integer(); });
}
