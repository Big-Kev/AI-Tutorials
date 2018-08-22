#pragma once
#include "SteeringForce.h"
class FleeForce :
	public SteeringForce
{
public:
	FleeForce();
	~FleeForce();

	Vector2 getForce(GameObject* gameObject);

	GameObject * m_target;
};

