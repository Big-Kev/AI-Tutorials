#pragma once
#include "Vector2.h"
#include "GameObject.h"
class SteeringForce
{
public:
	SteeringForce();
	virtual ~SteeringForce();

	virtual Vector2 getForce(GameObject* gameObject) = 0;
};

