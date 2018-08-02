#pragma once
#include "Vector2.h"
class Agent
{
public:
	Agent();
	~Agent();

	//void AddForce(Vector2 force) { m_acceleration = m_acceleration + force; };
	void AddForce(Vector2 force) { m_acceleration = m_acceleration + force; };

protected:
	Vector2 m_pos;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	float m_mass;
	//float m_force;

};

