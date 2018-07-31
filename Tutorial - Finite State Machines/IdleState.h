#pragma once
#include "State.h"
class IdleState :
	public State
{
public:
	IdleState() {}
	virtual ~IdleState() {}

	virtual void update(GameObject* gameObject, float deltaTime) {}

};

