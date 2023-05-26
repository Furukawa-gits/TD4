#pragma once
#include <RVector.h>
#include<ParticleManager.h>

#include "ProtoPlayer.h"

using namespace Rv3Ease;

class Head
{
public:

	Head() {};
	virtual ~Head() {};

	virtual void Init() {};

	virtual void ResetFrontEase() {};

	virtual void Update() {};

	virtual void Draw() {};

	virtual void Finalize() {};

	virtual void KramerMove() {};

	virtual void SlappingMove() {};

	virtual void FailMove() {};

	virtual void GoHome() {};

	static void setPlayerPtr(std::shared_ptr<ProtoPlayer> ptr);

	void SetPlayer(ProtoPlayer* ptr) {
		this->playerPtr = ptr;
	}

	void Activate() {
		isactive = true;
	}

public:
	//�r���^���ꂽ���̃p�[�e�B�N��
	std::unique_ptr<ParticleManager> SlapParticle;
	UINT slapTex;

	//�A�t�B���ϊ�
	RVector3 pos, rot, scale;

	//�q�̃^�C�v
	CheraType HeadType = CheraType::None;

	//�擪���ǂ���
	bool isMostFront = false;

	//�L�����t���O
	bool isactive = false;

	//�ҋ@����
	int waitTime = 0;
	const int MaxWaitTime = 1200;

	//�A�邩�ǂ���
	bool isGoHome = false;

	//����؂�ꂽ�E�����ꂽ���ǂ���
	bool isHairDestroy = false;

	//�ԈႦ�����ǂ���
	bool isFail = false;

	//�{���Ă��邩�ǂ���
	bool isAngree = false;

	//�{���Ă��鎞��
	int AngreeTime = 0;
	const int MaxAngreeTime = 180;

	//�������邩�ǂ���
	bool isCounter = false;

	//�������I��������ǂ���
	bool isAllMoveFinish = false;

	//�v���C���[�|�C���^
	ProtoPlayer* playerPtr;

	//�N���[�}�[���ǂ���
	bool isKramer = false;

	//�r���^�t���O
	bool isSlap = false;

	//�r���^���ꂽ��
	int SlapCount = 0;

	//�r���^�̍ő��
	const int ManSlapCount = 5;

	//�C�[�W���O�p�ϐ�
	//�O�ɐi�ގ�
	bool isFrontEase = false;		//�O�ɐi�ނ�
	RVector3 FrontStart = {};
	RVector3 FrontEnd = {};
	int FrontEaseT = 0;		//����
	const float FrontLength = 2.5f;	//�ω���
	//�r���^���ꂽ�Ƃ�
	float SlapEaseT = 0.0f;			//����
	const float SlapLength = 1.0f;	//�ω���
};

