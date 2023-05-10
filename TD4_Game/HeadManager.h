#pragma once
#include "Head.h"
#include "ProtoPlayer.h"

class HeadManager
{
private:
	//�\���ő吔
	static const int HEAD_DISPLAY_MAX = 5;
public:
	HeadManager();
	~HeadManager();
	void Initialize();
	void Update();
	void Draw();
	//�擪�̐l�������𔻕ʂ���
	CheraType GetFrontType();
private:
	//����X�|�[��
	void FirstSpawn();
	/// �X�|�[���Ǘ�
	Head *HeadSpawn(const int arrayNum);
	//�擪�̐l������
	void PopFront();
private:
	//���R���e�i
	std::vector<std::shared_ptr<Head>> heads;
	//�C�[�W���O�p���W
	std::array<RVector3, HEAD_DISPLAY_MAX> easepos;
	//����
	std::array<CheraType, HEAD_DISPLAY_MAX> charaType;
};

