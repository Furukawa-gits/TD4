#pragma once
#include <RVector.h>

#include "ProtoPlayer.h"

using namespace Rv3Ease;

class Head
{
public:

	Head() {};
	virtual ~Head() {};

	virtual void Init() {};

	virtual void Update() {};

	virtual void Draw() {};

	virtual void Finalize() {};

	virtual void SlappingMove() {};

	void SetPlayer(std::shared_ptr<ProtoPlayer> ptr) {
		this->ptr = ptr;
	}

	void Activate() {
		isactive = true;
	}

public:
	//�A�t�B���ϊ�
	RVector3 pos, rot, scale;

	//�q�̃^�C�v
	CheraType HeadType = CheraType::None;

	//�L�����t���O
	bool isactive = false;

	//�ҋ@����
	int waitTime = 0;

	//����؂�ꂽ�E�����ꂽ���ǂ���
	bool isHairDestroy = false;

	//�{���Ă��邩�ǂ���
	bool isAngree = false;

	//�{���Ă��鎞��
	int AngreeTime = 0;

	//�������邩�ǂ���
	bool isCounter = false;

	//�������I��������ǂ���
	bool isAllMoveFinish = false;

	//�v���C���[�|�C���^
	std::weak_ptr<ProtoPlayer> ptr;

	//�N���[�}�[���ǂ���
	bool isKramer = false;

	//�r���^�t���O
	bool isSlap = false;

	//�r���^���ꂽ��
	int SlapCount = 0;

	//�C�[�W���O�p�ϐ�
	//�O�ɐi�ގ�
	float FrontEaseT = 0.0f;		//����
	const float Length = 10.0f;		//�ω���
	//�r���^���ꂽ�Ƃ�
	float SlapEaseT = 0.0f;			//����
	const float SlapLength = 1.0f;	//�ω���
};

