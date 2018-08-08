#pragma once
#include "SteeringBehaviour.h"
#include <stdlib.h>    
#include <time.h>      

class WanderForce :
	public SteeringForce
{
public:
	WanderForce();
	~WanderForce();

	Vector2 getForce(GameObject* gameObject);
	void setPeram(float o, float r, float j);

protected:
	Vector2 m_target;
	Vector2 m_dir;
	float m_offset;
	float m_radius;
	float m_jitter;
	float target_accuracy_rec;


};

