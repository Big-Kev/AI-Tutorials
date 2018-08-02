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

	void setSteeringForce(SteeringForce* sf) { steeringForce = sf; }
protected:
	SteeringForce* steeringForce;
};

