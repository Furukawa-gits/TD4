#pragma once
#include "Quaternion.h"


//�J�����v�Z�N���X
//�J�����s��̋@�\�͊����̂��̂����A������v�Z���邽�߂ɕK�v�Ȍv�Z������
class CameraCalc
{
public:
	CameraCalc(){}
	~CameraCalc(){}

	void Init(RVector3 eyepos, RVector3 lookVec, RVector3 upVec, float rot = 0.0f);

	void CalcCamRotate(RVector3 rot);




public:
	//�e���̃J������]�p
	RVector3 _camrot;
	//���_���W
	RVector3 _eyepos;
	//�����_�x�N�g��
	RVector3 _targetVec;
	//��x�N�g��
	RVector3 _upVec;
	//�E�x�N�g��
	RVector3 _rightVec;


};

