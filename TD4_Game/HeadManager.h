#pragma once
#include "Head.h"
#include "ProtoPlayer.h"
#include"ScoreManager.h"
#include"NY_random.h"

class HeadManager
{
private:
	//�\���ő吔
	static const int HEAD_DISPLAY_MAX = 5;
	//�͂��̏o���m��
	static const int HAGEHEAD_SPAWN_NUM = 10;
	//��{�͂��̏o���m��
	static const int LIGHTHEAD_SPAWN_NUM = 20;
	//�A�t���̏o���m��
	static const int AFROHEAD_SPAWN_NUM = 30;
public:
	HeadManager(ProtoPlayer* player);
	~HeadManager();
	void Initialize();
	void Update();
	void Draw();
	void DrawUI();
	//�擪�̐l�������𔻕ʂ���
	CheraType GetFrontType();

	void TutorialInit();
	void TutorialUpdate();
public:
	const ScoreManager *GetScoreManager() { return scoreManager; }
	//���R���e�i
	std::vector<std::unique_ptr<Head>> heads;
private:
	//����X�|�[��
	void FirstSpawn();
	void TutorialFirstSpawn();
	/// �X�|�[���Ǘ�
	Head *HeadSpawn(const int arrayNum);
	//�擪�̐l������
	void PopFront();
private:
	//�C�[�W���O�p���W
	std::array<RVector3, HEAD_DISPLAY_MAX> easepos;
	//����
	std::array<CheraType, HEAD_DISPLAY_MAX> charaType;

	ProtoPlayer *player;

	ScoreManager *scoreManager;

	int tutorialNum;
};

