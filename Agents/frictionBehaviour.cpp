#include "frictionBehaviour.h"
#include "GameObject.h"

frictionBehaviour::frictionBehaviour()
{
}


frictionBehaviour::~frictionBehaviour()
{
}

eBehaviourResult frictionBehaviour::execute(GameObject * gameObject, float deltaTime)
{
	Vector2 m_temp;
	//m_temp = m_slowFactor;
	//
	//Vector2 m_slowFactor;
	//Vector2 temp;
	//gameObject->getVelocity(m_slowFactor);
	//temp = temp - m_slowFactor;
	//gameObject->addForce(temp, 1);


	gameObject->getVelocity(m_temp);
	float s = m_temp.magnitude();
	m_temp.normalise();
	Vector2 test;

	test.x = 0 - m_temp.x;
	test.y = 0 - m_temp.y;
	float m;
	gameObject->getMass(m);
	//gameObject->addForce(test, m_speed);
	//gameObject->addForce(test, s);
	return eBehaviourResult::SUCCESS;

}
