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
	static const int HAGEHEAD_SPAWN_NUM = 30;
	//��{�͂��̏o���m��
	static const int LIGHTHEAD_SPAWN_NUM = 30;
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
public:
	const ScoreManager *GetScoreManager() { return scoreManager; }
private:
	//����X�|�[��
	void FirstSpawn();
	/// �X�|�[���Ǘ�
	Head *HeadSpawn(const int arrayNum);
	//�擪�̐l������
	void PopFront();
private:
	//���R���e�i
	std::vector<std::unique_ptr<Head>> heads;
	//�C�[�W���O�p���W
	std::array<RVector3, HEAD_DISPLAY_MAX> easepos;
	//����
	std::array<CheraType, HEAD_DISPLAY_MAX> charaType;

	ProtoPlayer *player;

	ScoreManager *scoreManager;
};

