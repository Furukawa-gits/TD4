#pragma once
#include <RVector.h>

#include "ProtoPlayer.h"


class Head
{
public:

	Head() {};
	virtual ~Head() {};

	virtual void Init() {};

	virtual void Update() {};

	virtual void Draw() {};

	virtual void Finalize() {};

	virtual void SlappingMove() {};

	void SetPlayer(std::shared_ptr<ProtoPlayer> ptr) {
		this->ptr = ptr;
	}

	void Activate() {
		isactive = true;
	}

public:
	//�A�t�B���ϊ�
	RVector3 pos, rot, scale;

	//�L�����t���O
	bool isactive = false;

	//�v���C���[�|�C���^
	std::weak_ptr<ProtoPlayer> ptr;

};

