#pragma once
#include "Vector2.h"
#include "GameObject.h"
class SteeringForce
{
public:
	SteeringForce();
	virtual ~SteeringForce();

	Vector2 getForce(GameObject* gameObject) 
	{
		Vector2 v(0, 0);
		gameObject->getForce(v);
		return v;
	}

};

