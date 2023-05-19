#include "CameraCalc.h"

void CameraCalc::Init(RVector3 eyepos, RVector3 lookVec, RVector3 upVec,float rot)
{
	_eyepos = eyepos;
	_targetVec = lookVec;
	_upVec = upVec;

	//�����_�x�N�g�������Ƃɏ�����x�N�g������]
	RQuaternion P = quaternion(_upVec.x, _upVec.y, _upVec.z, 0.f);
	RQuaternion Q = quaternion(lookVec.x * sinf(rot / 2.0f),
		lookVec.y * sinf(rot / 2.0f),
		lookVec.z * sinf(rot / 2.0f),
		cosf(rot / 2.0f));
	RQuaternion R = quaternion(-lookVec.x * sinf(rot / 2.0f),
		-lookVec.y * sinf(rot / 2.0f),
		-lookVec.z * sinf(rot / 2.0f),
		cosf(rot / 2.0f));
	RQuaternion A = R * P * Q;
	_upVec = RVector3(A.x, A.y, A.z);

	//��x�N�g�������Ƃɒ����_�x�N�g��������]
	RQuaternion P2 = quaternion(_targetVec.x, _targetVec.y, _targetVec.z, 0.f);
	RQuaternion Q2 = quaternion(_upVec.x * sinf(rot / 2.0f),
		_upVec.y * sinf(rot / 2.0f),
		_upVec.z * sinf(rot / 2.0f),
		cosf(rot / 2.0f));
	RQuaternion R2 = quaternion(-_upVec.x * sinf(rot / 2.0f),
		-_upVec.y * sinf(rot / 2.0f),
		-_upVec.z * sinf(rot / 2.0f),
		cosf(rot / 2.0f));
	RQuaternion A2 = R2 * P2 * Q2;
	_targetVec = RVector3(A2.x, A2.y, A2.z);

	//��x�N�g���ƌ��_�̊O�ς�����ĉE�����̎�������

}

void CameraCalc::CalcCamRotate(RVector3 rot)
{
	//�����_�x�N�g�������x�N�g��




}
