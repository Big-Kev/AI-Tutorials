#include "SeekForce.h"



SeekForce::SeekForce()
{
}


SeekForce::~SeekForce()
{
}

Vector2 SeekForce::getForce(GameObject * gameObject)
{
	Vector2 target_pos;
	m_target->getPosition(target_pos);
	Vector2 pos;
	gameObject->getPosition(pos);
	float distance = (pos[0] - target_pos[0]) * (pos[0] - target_pos[0]) + (pos.y - target_pos.x) * (pos.y - target_pos.x);
	distance = sqrt(distance);
	if (distance > 0) {
		Vector2 target_dir = target_pos - pos;
		target_dir.normalise();
		return target_dir;
	}
	return Vector2(0, 0);
}
