#include "GameObject.h"
#include "Behaviour.h"



GameObject::GameObject()
{
	m_mass = 1;
}


GameObject::~GameObject()
{
}

void GameObject::addForce(Vector2 dir, float f, float deltaTime)
{
	dir.normalise();
	//m_acceleration = m_acceleration + (dir * (f / m_mass));
	m_acceleration = (m_acceleration + (dir * f))* deltaTime;
}

void GameObject::addForce(Vector2 dir)
{
	m_acceleration = dir;
}

void GameObject::decelerate(float d)
{
	m_velocity.shortenLength(d);
}

void GameObject::addBehaviour(Behaviour * behaviour)
{
	m_behaviours.push_back(behaviour);
}

void GameObject::update(float deltaTime)
{

	for (Behaviour* b : m_behaviours) {
		b->execute(this, deltaTime);
	}

	m_velocity = m_velocity + m_acceleration;
	
	if (m_velocity.x != 0 || m_velocity.y != 0) {
		if (m_velocity.magnitude() > m_maxVelocity) {
			m_velocity.normalise();
			m_velocity * m_maxVelocity;
		}
	}

	translate(m_velocity);

	m_acceleration.x = 0;
	m_acceleration.y = 0;
}
