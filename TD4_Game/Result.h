#pragma once

#include <vector>
#include <memory>
#include <array>
#include <NY_Object3dMgr.h>

#include "ProtoPlayer.h"
#include"BaseScene.h"
#include"ScoreManager.h"

class Result : public BaseScene
{
public:

	Result(ISceneChanger *changer);
	~Result();

	void Initialize() override;    //�������������I�[�o�[���C�h�B
	void Finalize() override;   //�I���������I�[�o�[���C�h�B
	void Update() override;        //�X�V�������I�[�o�[���C�h�B
	void Draw() override;          //�`�揈�����I�[�o�[���C�h�B
	void Draw2D() override;
private:

	std::shared_ptr<Object3d> groundObject;

	UINT groundTex;
};

