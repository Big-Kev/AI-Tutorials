#pragma once
#include "SteeringForce.h"
class PursueForce :
	public SteeringForce
{
public:
	PursueForce();
	~PursueForce();

	Vector2 getForce(GameObject* gameObject);

	GameObject * m_target;
};

