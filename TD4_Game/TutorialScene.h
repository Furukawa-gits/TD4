#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "FbxLoader.h"
#include <DirectXMath.h>
#include <cmath>

#include <Raki_Input.h>
#include <NY_Object3DMgr.h>
#include <Sprite.h>

#include "Head.h"
#include "ProtoPlayer.h"
#include"HeadManager.h"

class TutorialScene : public BaseScene
{
public:
	TutorialScene(ISceneChanger *changer);
	~TutorialScene() override;
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override;   //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;          //�`�揈�����I�[�o�[���C�h�B
    void Draw2D() override;
    void DrawImgui() override;

private:
    std::unique_ptr<HeadManager> headMan;

    std::unique_ptr<ProtoPlayer> player;

    //���̑�
    std::shared_ptr<Object3d> groundObject;

    UINT groundTex;
};

