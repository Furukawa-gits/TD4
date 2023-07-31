#pragma once
#include "ISceneChanger.h"
#include "BaseScene.h"

/// <summary>
/// �V�[���Ǘ��N���X�@�d�l
/// <para>�ڂ����� dixq.net/g/sp_06.html ���Q�Ƃ��邱��</para>
/// <para>�E�e�V�[���̃N���X�̃C���X�^���X�𐶐����A���݂̃V�[���̏����̂ݎ��s����</para>
/// <para>�E�e�V�[���̃N���X�̃I�[�o�[���C�h�֐��́A������Raki_DX12B�N���X���擾����</para>
/// <para>�E�g�p���́A���̃N���X�̃C���X�^���X��main�Ő����AInit�AUpdate�ADraw�A(�K�v�ɉ�����Finalize)�����s�����OK</para>
/// <para>�E�V�[���ύX���s���́A�e�N���X�̍X�V������ChangeScene(�����Fenum�Œ�`�����V�[���ԍ�)�֐������s���邱�ƂŁA</para>
/// <para>�@�O�V�[���̏I�����������s�A���V�[���̏������J�n����</para>
/// </summary>
class SceneManager : public ISceneChanger ,Task
{
private:

    BaseScene *nowScene;
	eScene mNextScene;    //���̃V�[���Ǘ��ϐ�

    std::shared_ptr<SceneChangeDirection> mSceneChangeDirection;
    bool isChangeDirectioning = false;

public:
    //�R���X�^���N�^
    SceneManager();
    ~SceneManager() override;
    void Initialize() override;//������
    void Finalize() override;//�I������
    void Update() override;//�X�V
    void Draw() override;//�`��
    void Draw2D() override;
    void DrawImgui() override;

    void DrawParticle();

    // ���� nextScene �ɃV�[����ύX����
    void ChangeScene(eScene NextScene) override;

};

