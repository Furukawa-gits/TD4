#pragma once
#include "BaseScene.h"

#include <NY_Object3DMgr.h>
#include <Sprite.h>
#include <Raki_Input.h>

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

    Sprite testsp;
    std::shared_ptr<Object3d> testobject;

    std::shared_ptr<Object3d> testFBX_YesBone;
    std::shared_ptr<Object3d> testFBX_NoBone;

};

