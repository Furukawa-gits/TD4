#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "FbxLoader.h"
#include <DirectXMath.h>
#include <cmath>

#include <Raki_Input.h>
#include <NY_Object3DMgr.h>
#include <Sprite.h>

enum DIRECTION_STATUS
{
	DIRECTION_STANDBY,
	DIRECTION_IN,
	DIRECTION_OUT,
	DIRECTION_ENDED,
};

class SceneChangeDirection
{
public:
	SceneChangeDirection();

	~SceneChangeDirection();

	//���o������
	void Init();
	//�V�[���J�n���o�J�n
	void PlayInDirection();
	//�V�[���I�����o�J�n
	void PlayOutDirection();
	//�X�V�i���t���[�����s�j
	void Update();
	//�`��
	void Draw();

	DIRECTION_STATUS GetDirectionStatus() { return status; }

private:
	//���o�ɕK�v�ȕϐ��͂���

	Sprite spriteBlack;
	XMFLOAT2 spritePos;
	XMFLOAT2 spriteSize;
	const int animationCountMax = 60;
	int animationCount = 0;
	bool isAnimation = false;

	DIRECTION_STATUS status;
	DIRECTION_STATUS drawingStatus;

	const RVector3 WINDOW_CENTER = RVector3(640, 360, 0);

	const float EASE_MOVE_X_MAX = 640.f;
	const float EASE_MOVE_Y_MAX = 360.f;


	Rv3Ease::Rv3Easing inDirect, outDirect;
};

