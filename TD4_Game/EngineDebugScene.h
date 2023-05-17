#pragma once
#include "BaseScene.h"

#include <NY_Object3DMgr.h>
#include <Sprite.h>
#include <Raki_Input.h>

#include <CameraCalc.h>

//�G���W�������ؗp�V�[��
//���̃N���X��������Ȃ�����
class EngineDebugScene : public BaseScene
{
public:
    EngineDebugScene(ISceneChanger* changer);
    ~EngineDebugScene() override;
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B
    void Draw2D() override;
    void DrawImgui() override;

    Sprite testsp;
    std::shared_ptr<Object3d> testobject;

    std::shared_ptr<Object3d> testFBX_YesBone;
    std::shared_ptr<Object3d> testFBX_NoBone;

    Rv3Ease::Rv3Easing testEase;

    int testmode = 0;
    int testanimnum = 0;

    //�f�o�b�O�p�ϐ�
    float rotX = 0.f, rotY = 0.f, rotZ = 0.f;

    float camrot = 0.f;

    CameraCalc testcam;
};

