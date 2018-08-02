#pragma once
#include "Behaviour.h"
#include "SteeringForce.h"
class SteeringBehaviour :
	public Behaviour
{
public:
	SteeringBehaviour();
	~SteeringBehaviour();


	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);

protected:
	SteeringForce* steeringForce;
};

