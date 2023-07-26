#pragma once
#include "Task.h"
#include "ISceneChanger.h"
#include "Raki_DX12B.h"
#include "Raki_WinAPI.h"
#include <wrl.h>

#include "SceneChangeDirection.h"

using namespace Microsoft::WRL;

class SceneChangeDirection;

class BaseScene : public Task {

    //template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

protected:
    
    ISceneChanger *mSceneChanger = nullptr;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X
    SceneChangeDirection* mSceneChangeDirection = nullptr;

public:
    BaseScene(ISceneChanger* changer, SceneChangeDirection* scDirect);
    BaseScene() {};
    virtual ~BaseScene() {

    }


    virtual void Initialize() override {}    //�������������I�[�o�[���C�h�B
    virtual void Finalize() override {}        //�I���������I�[�o�[���C�h�B
    virtual void Update() override {}        //�X�V�������I�[�o�[���C�h�B
    virtual void Draw() override{}            //�`�揈�����I�[�o�[���C�h�B
    virtual void Draw2D() override{}
    virtual void DrawImgui() override{}
    virtual void DrawParticle() {}
};

