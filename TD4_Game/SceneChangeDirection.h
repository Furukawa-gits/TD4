#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "FbxLoader.h"
#include <DirectXMath.h>
#include <cmath>

#include <Raki_Input.h>
#include <NY_Object3DMgr.h>
#include <Sprite.h>

class SceneChangeDirection
{
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

private:
	//���o�ɕK�v�ȕϐ��͂���

	Sprite spriteBlack;
	XMFLOAT2 spritePos;
	XMFLOAT2 spriteSize;
	const int animationCountMax = 180;
	int animationCount = 0;
	bool isAnimation = false;
};

