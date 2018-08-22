#pragma once
#include "Behaviour.h"
#include "SteeringForce.h"
#include <vector>
class SteeringBehaviour :
	public Behaviour
{
public:
	SteeringBehaviour();
	~SteeringBehaviour();


	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);

	void setSteeringForce(SteeringForce* sf) { steeringForce = sf; }
	void addSteeringForce(SteeringForce* sf) { steeringForces.push_back(sf); }
protected:
	SteeringForce* steeringForce;
	std::vector<SteeringForce*> steeringForces;
};

