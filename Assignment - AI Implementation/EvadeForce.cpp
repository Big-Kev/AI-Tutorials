#include "EvadeForce.h"



EvadeForce::EvadeForce()
{
}


EvadeForce::~EvadeForce()
{
}

Vector2 EvadeForce::getForce(GameObject * gameObject)
{
	Vector2 target_pos;
	Vector2 target_velocity;
	Vector2 target_acc;
	m_target->getPosition(target_pos);
	m_target->getVelocity(target_velocity);
	m_target->getAcceleration(target_acc);

	target_pos = target_pos + (target_velocity + target_acc);

	Vector2 pos;
	gameObject->getPosition(pos);
	float distance = (pos[0] - target_pos[0]) * (pos[0] - target_pos[0]) + (pos.y - target_pos.x) * (pos.y - target_pos.x);
	distance = sqrt(distance);
	if (distance > 0) {
		Vector2 target_dir = target_pos - pos;
		target_dir.normalise();
		target_dir = target_dir * -1;
		return target_dir;
	}
	return Vector2(0, 0);
}
