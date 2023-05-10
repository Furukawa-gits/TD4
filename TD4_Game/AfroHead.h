#pragma once
#include "Head.h"

#include <NY_Object3dMgr.h>
#include <memory>

class AfroHead : public Head
{
public:
	AfroHead();
	~AfroHead();

	void Init() override;

	void Update() override;

	void Draw() override;

	void Finalize() override;

	void SlappingMove() override;

private:
	void CuttingHair();

private:

	std::shared_ptr<Object3d> headObject;
	std::shared_ptr<Object3d> afroObject;

	//�ʒu�̃I�t�Z�b�g
	RVector3 headOffset;
	RVector3 hairOffset;

	UINT afroheadTex;

	//�����a������
	int CutCount = 0;
	const int MaxCutCount = 3;

};

