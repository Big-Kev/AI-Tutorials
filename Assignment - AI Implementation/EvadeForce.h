#pragma once
#include "SteeringForce.h"
class EvadeForce :
	public SteeringForce
{
public:
	EvadeForce();
	~EvadeForce();
	Vector2 getForce(GameObject* gameObject);

	GameObject * m_target;
};

