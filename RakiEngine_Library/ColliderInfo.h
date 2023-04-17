#pragma once
#include <string>

#include "RVector.h"

class BaseCollider;
class Object3d;
class GameObject;

class ColliderInfo
{
public:
	ColliderInfo(RVector3 inter,std::string tag);

	//衝突点
	RVector3 inter;
	//タグ名
	std::string tag;

};

