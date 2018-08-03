#pragma once
#include "SteeringBehaviour.h"
#include <stdlib.h>    
#include <time.h>      

class WanderForce :
	public SteeringBehaviour
{
public:
	WanderForce();
	~WanderForce();

	Vector2 getForce(GameObject* gameObject);


protected:
	Vector2 m_target;
	Vector2 m_dir;
	float m_offset;
	float m_radius;
	float m_jitter;



};

