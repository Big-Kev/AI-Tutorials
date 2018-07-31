#pragma once
#include "State.h"
class AttackState :
	public State
{
public:
	AttackState(GameObject* target, float speed) : m_target(target), m_speed(speed) {}
	virtual ~AttackState() {}
	virtual void update(GameObject* gameObject, float deltaTime);

private:
	float m_speed;
	GameObject* m_target;
};

