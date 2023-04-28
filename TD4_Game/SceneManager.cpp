#include "SceneManager.h"
#include "GameScene.h"
#include "TitleScene.h"

//Raki_DX12B         *SceneManager::dx12b  = nullptr;
//NY_Object3DManager *SceneManager::objmgr = nullptr;
//SpriteManager      *SceneManager::spmgr  = nullptr;

SceneManager::SceneManager() :mNextScene(eScene_None) {

    //�e�V�[���̃C���X�^���X����
    nowScene = (BaseScene *) new TitleScene(this);
    Initialize();
}

void SceneManager::Initialize()
{
    //�V�[���̏�����
	nowScene->Initialize();
}

void SceneManager::Finalize()
{
    nowScene->Finalize();
}

void SceneManager::Update()
{
    if (mNextScene != eScene_None) {    //���̃V�[�����Z�b�g����Ă�����
        delete nowScene;
        nowScene = nullptr;
        
        switch (mNextScene) {       //�V�[���ɂ���ď����𕪊�
        case eScene_Title:        //���̉�ʂ����j���[�Ȃ�
            nowScene = (BaseScene*) new TitleScene(this);
            break;//�ȉ���
        case eScene_Game:
            nowScene = (BaseScene*) new GameScene(this);
            break;
        }
        mNextScene = eScene_None;    //���̃V�[�������N���A
    }

    nowScene->Update(); //�V�[���̍X�V
}

void SceneManager::Draw()
{
    //���݃V�[���̕`�揈�������s
    nowScene->Draw();
}

void SceneManager::Draw2D()
{
    nowScene->Draw2D();
}

void SceneManager::ChangeScene(eScene NextScene)
{
    //���̃V�[���ԍ����Z�b�g
    mNextScene = NextScene;
}
