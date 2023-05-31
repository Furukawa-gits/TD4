#pragma once
#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "FbxLoader.h"
#include <DirectXMath.h>
#include <cmath>

#include <Raki_Input.h>
#include <NY_Object3DMgr.h>
#include <Sprite.h>

class ResultScene : public BaseScene
{
public:
	ResultScene(ISceneChanger* changer);
	~ResultScene() override;

    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override;   //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;          //�`�揈�����I�[�o�[���C�h�B
    void Draw2D() override;
    void DrawImgui() override;

    void Animation();

    Sprite spriteStar[5];
    Sprite scoreTex;
    std::shared_ptr<Object3d> testobject;
    std::shared_ptr<Object3d> resultPlayer;

    const int animationCountMax = 1200;
    int animationCount = 0;
    bool starIsDraw;
    bool scoreTexIsDraw;

    XMFLOAT2 starPos;
};

