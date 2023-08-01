#pragma once

//RakiEngine
#include <Sprite.h>
#include <RVector.h>

//web�T�[�o�[�֘A
#include <cpprest/filestream.h>
#include <cpprest/http_client.h>
#include <cpprest/json.h>

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

//TD4Game�̃����L���O�Ǘ��V�X�e��
//SQL�ւ̃f�[�^���M�A�f�[�^�擾�A�`���S��

class RankingManager
{
public:
	RankingManager() = default;
	~RankingManager();

	void Init();

	void Update();

	void Draw2D();

	void DebugDraw();

	//�X�R�A���T�[�o�[�ɑ��M�iresultScene�̃X�R�A�ϐ����K�v�j
	void PostScore(int score);
	//�X�R�A�f�[�^���擾���A�z��Ɋi�[
	std::array<int, 5> GetRanking();

	//���U���g�\���J�n
	void StartDisplayResults();

private:
	template <class T>
	//�����L���O�f�[�^�擾
	pplx::task<T> Get(const std::wstring& url);
	//�����L���O�f�[�^���M
	pplx::task<int> Post(const std::wstring& url, int score);

	//�����L���O�f�[�^�z��
	std::array<int, 5> rankingArray = { 5,4,3,2,1 };

	//�����L���O�f�[�^�擾�ς𔻒�
	bool isRankingGot = false;
	bool isRankingSend = false;

	web::json::value json;
	web::json::value response;

	//�����L���O�\���C�[�W���O
	std::array<Rv3Ease::Rv3Easing, 5> rankScoreEase;

	//���l�X�v���C�g
	Sprite numSprite;

	//���o�J�n�t���O
	bool isStartDisplayRank = false;

	//�o�߃t���[��
	int frame = 0;

};
