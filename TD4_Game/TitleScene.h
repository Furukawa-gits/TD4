#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "FbxLoader.h"

#include <NY_Object3DMgr.h>
#include <Sprite.h>

class TitleScene : public BaseScene {

public:
    TitleScene(ISceneChanger *changer);
    ~TitleScene() override;

    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override ;   //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;          //�`�揈�����I�[�o�[���C�h�B
    void Draw2D() override;
    void DrawImgui() override;

    void Animation();

    Sprite testsp;
    std::shared_ptr<Object3d> testobject;

    std::shared_ptr<Object3d> titleHage;
    std::shared_ptr<Object3d> titlePlayer;

    const int animationCountMax = 1200;
    int animationCount = 0;

    XMFLOAT2 titleSpritePos;

    RVector3 testObjPos;
    RVector3 testPlayerPos;
    RVector3 testHagePos;
};

