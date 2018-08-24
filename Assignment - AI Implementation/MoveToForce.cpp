#include "MoveToForce.h"



MoveToForce::MoveToForce()
{
}


MoveToForce::~MoveToForce()
{
}

Vector2 MoveToForce::getForce(GameObject * gameObject)
{
	Vector2 m_pos;
	Vector2 target_dir;
	gameObject->getPosition(m_pos);
	target_dir = m_targetPos - m_pos;
	if (m_pos.pythag(m_targetPos) < (m_speed*m_speed) + 2) {
		gameObject->setPosition(m_targetPos);
		return Vector2(0,0);
	}

	target_dir.normalise();
	target_dir = target_dir * m_speed;

	return target_dir;
}
