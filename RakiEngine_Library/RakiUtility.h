#pragma once
#include <iostream>
#include <cstdlib>
#include <math.h>

#include "RVector.h"

#include <string>

//�����̊֐��Ƃ��Ԃ�Ȃ��悤��
//��ނ��������炱�̒����炳��ɖ��O��ԕ�������
namespace rutility
{

	//���l�������̌��𐮐��ŏo�́i���́A������1�ʂ�0�A�������͐��A�������͕��Ŏ����j
	int GetDigits(float value, int left, int right);





	RVector3 randomRV3(RVector3 pos1, RVector3 pos2);


	std::wstring charTowstring(const char* orig);
}


