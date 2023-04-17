#include<iostream>

#include "Raki_DX12B.h"
#include "FPS.h"
#include "Audio.h"
#include "TexManager.h"
#include <RenderTargetManager.h>

#include "NY_Object3DMgr.h"
#include "SpriteManager.h"
#include "Raki_imguiMgr.h"

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

    Raki_DX12B::Get()->Initialize(rakiWinApp);

    myImgui::InitializeImGui(Raki_DX12B::Get()->GetDevice(), Raki_WinAPI::GetHWND());

    //�I�u�W�F�N�g�Ǘ�
    NY_Object3DManager::Get()->CreateObject3DManager();
    SpriteManager::Get()->CreateSpriteManager(Raki_DX12B::Get()->GetDevice(), Raki_DX12B::Get()->GetGCommandList(),
        rakiWinApp->window_width, rakiWinApp->window_height);
    TexManager::InitTexManager();

    //��
    Audio::Init();

    //�V�[���Ǘ�

#pragma endregion GameValue

    FPS::Get()->Start();

    while (true)  // �Q�[�����[�v
    {
        if (rakiWinApp->ProcessMessage()) { break; }

        //�X�V
        Input::StartGetInputState();



        RenderTargetManager::GetInstance()->CrearAndStartDraw();



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