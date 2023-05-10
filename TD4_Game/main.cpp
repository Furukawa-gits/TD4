#include<iostream>

#include "Raki_DX12B.h"
#include "FPS.h"
#include "Audio.h"
#include "TexManager.h"
#include <RenderTargetManager.h>
#include <DifferrdRenderingMgr.h>
#include "SceneManager.h"

#include "NY_Object3DMgr.h"
#include "SpriteManager.h"
#include "Raki_imguiMgr.h"
#include <NY_Camera.h>

#include "GameManager.h"

using namespace DirectX;
using namespace Microsoft::WRL;

//-----------RakiEngine_Alpha.ver-----------//


//�R���\�[���\���p�G���g���[�|�C���g�؂�ւ�
//Release�ł��R���\�[���������ꍇ�A�v���p�e�B->�����J�[->�T�u�V�X�e�����R���\�[���ɐ؂�ւ��Ă���AWinMain��main�ɂ���
#ifdef _DEBUG
int main()
#else
// Windows�A�v���ł̃G���g���[�|�C���g(main�֐�)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
#endif
{

#pragma region GameValue

    Raki_WinAPI* rakiWinApp;
    rakiWinApp = new Raki_WinAPI;
    rakiWinApp->CreateGameWindow();

    //�G���W�����̃G���[�A�x���𖳎����Ȃ��ݒ�ɂ���Ƃ��́A���̊֐��̑�������true��n���Ɨǂ�
    Raki_DX12B::Get()->Initialize(rakiWinApp, false);

    myImgui::InitializeImGui(Raki_DX12B::Get()->GetDevice(), Raki_WinAPI::GetHWND());

    //�I�u�W�F�N�g�Ǘ�
    NY_Object3DManager::Get()->CreateObject3DManager();
    SpriteManager::Get()->CreateSpriteManager(Raki_DX12B::Get()->GetDevice(), Raki_DX12B::Get()->GetGCommandList(),
        rakiWinApp->window_width, rakiWinApp->window_height);
    TexManager::InitTexManager();

    //��
    Audio::Init();

    DiferredRenderingMgr diffMgr;
    diffMgr.Init(RAKI_DX12B_DEV, RAKI_DX12B_CMD);

    //�V�[���Ǘ�
    RVector3 eye(0.f, 100.f, -100.f);
    RVector3 target(0.f, 0.f, 0.f);
    RVector3 up(0.f, 1.f, 0.f);
    NY_Camera::Get()->SetViewStatusEyeTargetUp(eye, target, up);



    std::unique_ptr<SceneManager> sceneMgr = std::make_unique<SceneManager>();




#pragma endregion GameValue

    FPS::Get()->Start();

    while (true)  // �Q�[�����[�v
    {
        if (rakiWinApp->ProcessMessage()) { break; }

        //�X�V
        Input::StartGetInputState();


        //�X�V�����܂�

        sceneMgr->Update();

        //�`�悱������
        RenderTargetManager::GetInstance()->CrearAndStartDraw();

        NY_Object3DManager::Get()->SetCommonBeginDrawObject3D();

        sceneMgr->Draw();

        NY_Object3DManager::Get()->CloseDrawObject3D();

        diffMgr.Rendering(&NY_Object3DManager::Get()->m_gBuffer, &NY_Object3DManager::Get()->m_shadomMap);

        SpriteManager::Get()->SetCommonBeginDraw();

        sceneMgr->Draw2D();

        sceneMgr->DrawImgui();

        //�`�悱���܂�
        RenderTargetManager::GetInstance()->SwapChainBufferFlip();

        FPS::Get()->run();
    }



    //imgui�I��
    myImgui::FinalizeImGui();

    // �E�B���h�E�N���X��o�^����
    rakiWinApp->DeleteGameWindow();

    delete rakiWinApp;
    rakiWinApp = nullptr;

    return 0;
}