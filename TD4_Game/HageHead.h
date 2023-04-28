#pragma once
#include "Head.h"

#include <NY_Object3dMgr.h>
#include <memory>

class HageHead : public Head
{
public:
	HageHead();
	~HageHead();

	void Init() override;

	void Update() override;

	void Draw() override;

	void Finalize() override;

	void SlappingMove() override;

private:

	std::shared_ptr<Object3d> headObject;

	//�ʒu�̃I�t�Z�b�g
	RVector3 headOffset;

	UINT hageheadTex;
};

