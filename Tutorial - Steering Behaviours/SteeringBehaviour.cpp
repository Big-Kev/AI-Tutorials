#include "SteeringBehaviour.h"



SteeringBehaviour::SteeringBehaviour()
{
}


SteeringBehaviour::~SteeringBehaviour()
{
}

eBehaviourResult SteeringBehaviour::execute(GameObject * gameObject, float deltaTime)
{
	Vector2 v = steeringForce->getForce(gameObject);
	gameObject->addForce(v);

	return eBehaviourResult::SUCCESS;
}
