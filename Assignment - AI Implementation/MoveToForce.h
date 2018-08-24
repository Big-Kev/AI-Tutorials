#pragma once
#include "SteeringForce.h"
#include <vector>
class MoveToForce :
	public SteeringForce
{
public:
	MoveToForce();
	~MoveToForce();

	Vector2 getForce(GameObject* gameObject);
	void setSpeed(float s) { m_speed = s; }
	void setTarget(Vector2* v) { m_targetPos = *v; }
	void setPath(std::vector<Vector2> * p) { path = p; }
	
	std::vector<Vector2> * path;
	GameObject * m_target;
	Vector2 m_targetPos;
	float m_speed;
};

