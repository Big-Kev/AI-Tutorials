#pragma once
#include "SteeringBehaviour.h"
class WanderForce :
	public SteeringBehaviour
{
public:
	WanderForce();
	~WanderForce();

	Vector2 getForce(GameObject* gameObject);

protected:
	Vector2 m_target;
	float m_offset;
	float m_radius;
	float m_jitter;


};

