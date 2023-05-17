#include "SceneManager.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "EngineDebugScene.h"
#include"Result.h"

//Raki_DX12B         *SceneManager::dx12b  = nullptr;
//NY_Object3DManager *SceneManager::objmgr = nullptr;
//SpriteManager      *SceneManager::spmgr  = nullptr;

SceneManager::SceneManager() :mNextScene(eScene_None) {

    //�e�V�[���̃C���X�^���X����
    nowScene = (BaseScene *) new TitleScene(this);
    Initialize();
}

SceneManager::~SceneManager()
{
    delete nowScene;
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
    //�f�o�b�O���[�h
    if (Input::Get()->isKeyTrigger(DIK_F12)) { mNextScene = eScene_Debug; }
    if(Input::Get()->isKeyTrigger(DIK_F1)) { mNextScene = eScene_Title; }

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
        case eScene_Result:
            nowScene = (BaseScene *) new Result(this);
            break;
        case eScene_Debug:
            nowScene = (BaseScene*) new EngineDebugScene(this);
            break;
        }
        mNextScene = eScene_None;    //���̃V�[�������N���A

        nowScene->Initialize();
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

void SceneManager::DrawImgui()
{
    nowScene->DrawImgui();
}

void SceneManager::ChangeScene(eScene NextScene)
{
    //���̃V�[���ԍ����Z�b�g
    mNextScene = NextScene;
}
