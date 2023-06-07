#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "NY_Object3DMgr.h"
#include "Raki_Input.h"
#include "GameManager.h"

#include <NY_Object3DMgr.h>
#include <Sprite.h>

class GameScene : public BaseScene {
public:
    GameScene(ISceneChanger *changer);
    ~GameScene() override;
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B
    void Draw2D() override;
    void DrawImgui() override;

    Sprite testsp;
    //std::shared_ptr<Object3d> testobject;

    GameManager gmgr;
};

