#pragma once
#include <vector>
#include <memory>
#include <array>
#include <NY_Object3dMgr.h>
#include <Sprite.h>

#include "Head.h"
#include "ProtoPlayer.h"

class Title
{
public:
	Title();
	~Title();

	void Init();

	void Update();

	void Draw();

	void UIDraw();

	void Finalize();

private:
	//3D�f��
	//�^�C�g���w�i
	Object3d titleBack3D;

	//2D�f��
	//�^�C�g���w�i
	Sprite titleBack2D;
	//�^�C�g�����S
	Sprite titleLogo;
	//�X�^�[�g�{�^��UI
	Sprite startButtonUI;

	//�ϐ�

};