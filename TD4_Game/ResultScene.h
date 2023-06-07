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

    Sprite spriteReview;
    Sprite spriteScore;

    std::shared_ptr<Object3d> resultPlayer;

    const int animationCountMax = 600;
    int animationCount = 0;
    bool starIsDraw;
    bool scoreTexIsDraw;

    //�����I�ȃX�R�A
    float totalScore;
    //�����I�ȃ��r���[
    float totalReview;
    //���΂�����
    int handleNum;

    XMFLOAT2 starPos;

    //�J�������̈ʒu
    const XMFLOAT2 HANDLE_POS = { 512,0 };
    const XMFLOAT2 TOTALREVIEW_POS = { 512,64 };
    const float SCORE_POS_X = 765.0f;
    const float SCORE_POS_Y = 360.0f;
};

