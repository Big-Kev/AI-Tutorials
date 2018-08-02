#include "SteeringBehaviour.h"



SteeringBehaviour::SteeringBehaviour()
{
}


SteeringBehaviour::~SteeringBehaviour()
{
}

eBehaviourResult SteeringBehaviour::execute(GameObject * gameObject, float deltaTime)
{
	gameObject->addForce(steeringForce->getForce(gameObject));

	return eBehaviourResult::SUCCESS;
}
