#include "LightHearHead.h"

LightHairHead::LightHairHead()
{
}

LightHairHead::~LightHairHead()
{
}

void LightHairHead::Init()
{
	lighthairTex = TexManager::LoadTexture("Resources/blackParticleTex.png");

	headObject = std::make_shared<Object3d>();
	hairObject = std::make_shared<Object3d>();

	headObject.reset(NY_Object3DManager::Get()->CreateModel_Box(5.f, 1.f, 1.f, lighthairTex));
	hairObject.reset(NY_Object3DManager::Get()->CreateModel_Box(10.f, 1.f, 1.f, lighthairTex));

	scale = RVector3(1, 1, 1);
	rot = RVector3(0, 0, 0);
	pos.zero();
	headObject->SetAffineParam(scale, rot, pos);
	hairObject->SetAffineParam(scale, rot, pos);
}

void LightHairHead::Update()
{
	// �����L�������ꂽ��
	if (isactive) {
		//���͂��󂯕t����

	}


	//�I�u�W�F�N�g�`��ʒu��ݒ�
	headObject->SetAffineParamTranslate(pos + headOffset);
	hairObject->SetAffineParamTranslate(pos + hairOffset);
}

void LightHairHead::Draw()
{
	//�I�u�W�F�N�g�`��
	headObject->DrawObject();
	hairObject->DrawObject();
}

void LightHairHead::Finalize()
{
}

void LightHairHead::SlappingMove()
{
}

void LightHairHead::PullOutHair()
{
}
