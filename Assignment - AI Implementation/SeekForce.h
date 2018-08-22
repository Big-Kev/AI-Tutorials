#pragma once
#include "SteeringForce.h"
class SeekForce :
	public SteeringForce
{
public:
	SeekForce();
	~SeekForce();
	Vector2 getForce(GameObject* gameObject);
	
	GameObject * m_target;
protected:
};

