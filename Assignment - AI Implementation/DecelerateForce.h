#pragma once
#include "SteeringForce.h"
class DecelerateForce :
	public SteeringForce
{
public:
	DecelerateForce();
	~DecelerateForce();

	Vector2 getForce(GameObject* gameObject);

	GameObject * m_target;
};

