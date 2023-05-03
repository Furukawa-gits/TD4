#pragma once
#include "Task.h"
#include "ISceneChanger.h"
#include "Raki_DX12B.h"
#include "Raki_WinAPI.h"
#include <wrl.h>

using namespace Microsoft::WRL;

/// <summary>
/// �e�V�[���̊��N���X�A�e�V�[���͂�����p�����邱�ƂŎ���
/// <para>���N���X�̓����o�ϐ��Ƃ��āARakiDX12�ANY_Object3DManager�ASpriteManager������</para>
/// <para>����ɂ��A�h�����Object3D�ASprite�̃C���X�^���X���g�p������AManager�̋@�\���g�p�\</para>
/// </summary>
class BaseScene : public Task {

    //template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

protected:
    
    ISceneChanger *mSceneChanger = nullptr;    //�N���X���L���ɃV�[���؂�ւ���`����C���^�[�t�F�C�X

public:
    BaseScene(ISceneChanger *changer);
    BaseScene() {};
    virtual ~BaseScene() {

    }


    virtual void Initialize() override {}    //�������������I�[�o�[���C�h�B
    virtual void Finalize() override {}        //�I���������I�[�o�[���C�h�B
    virtual void Update() override {}        //�X�V�������I�[�o�[���C�h�B
    virtual void Draw() override{}            //�`�揈�����I�[�o�[���C�h�B
    virtual void Draw2D() override{}

};

