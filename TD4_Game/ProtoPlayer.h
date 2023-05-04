#pragma once

#include <vector>
#include <memory>
#include <array>
#include <NY_Object3D.h>



enum CheraType
{
	None,SkinHead, Thinning, Afro,
};

class ProtoPlayer
{
public:
	ProtoPlayer();
	~ProtoPlayer();

	void Init();

	void Update();

	void Draw();

	void Finalize();

	//�r���^
	void HandAttack();

	//����؂�
	void CutHair();

	//����̃A�C�e����؂�ւ���
	void ChangeItem();

	enum ItemType
	{
		Hand, Scissors, Clippers
	};

private:
	
	RVector3 position;
	RVector3 rotation;
	RVector3 scale;
	int enemyType = SkinHead;
	int handItemType = Hand;

	std::shared_ptr<Object3d> player = nullptr;
	std::shared_ptr<Object3d> scissor = nullptr;

	UINT modelPlayer;
};

