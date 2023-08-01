#include "RankingManager.h"

#include <Raki_imguiMgr.h>

RankingManager::~RankingManager()
{
}

void RankingManager::Init()
{
    GetRanking();

    numSprite.CreateAndSetDivisionUVOffsets(10, 10, 1, 64, 64,
        TexManager::LoadTexture("Resources/Score.png"));


    //�����L���O�\��X����W
    const float EASE_LEFT_OFFSET = 600.0f;
    //�����L���O�\��Y����W
    const float EASE_TOP_OFFSET = 160.0f;
    //�����L���O�\��Y�\���Ԋu
    const float EASE_Y_OFFSET = 64.0f;

    //�C�[�W���O���W�ݒ�
    for (int i = 0; i < rankScoreEase.size(); i++) {
        float ypos = EASE_TOP_OFFSET + (EASE_Y_OFFSET * (i + 1));

        rankScoreEase[i].Init(Rv3Ease::RV3_EASE_TYPE::EASE_CUBIC_OUT,
            RVector3(1500.f, ypos, 0),
            RVector3(EASE_LEFT_OFFSET, ypos, 0),
            60);
    }

}

void RankingManager::Update()
{
    if (isStartDisplayRank) {
        frame++;

        for (int i = 0; i < 5; i++) {
            if (frame % (15 * (i + 1)) == 0) {
                rankScoreEase[i].Play();
            }
            rankScoreEase[i].Update();
        }
    }
}


void RankingManager::Draw2D()
{
    if (!isStartDisplayRank) { return; }

    //�����T�C�Y
    const float FONT_SIZE = 64.f;
    //�X�R�A�̕\���ʒu�I�t�Z�b�g
    const float SCORE_POS_X_OFFSET = 120.f;

    for (int i = 0; i < 5;i++) {
        //����
        numSprite.DrawNumSprite(rankScoreEase[i].GetNowpos().x,
            rankScoreEase[i].GetNowpos().y,
            FONT_SIZE,
            FONT_SIZE,
            i + 1);
        //�X�R�A
        numSprite.DrawNumSprite(rankScoreEase[i].GetNowpos().x + SCORE_POS_X_OFFSET,
            rankScoreEase[i].GetNowpos().y,
            FONT_SIZE,
            FONT_SIZE,
            rankingArray[i] + 10000);
    }

    numSprite.Draw();
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

void RankingManager::StartDisplayResults()
{
    isStartDisplayRank = true;
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
