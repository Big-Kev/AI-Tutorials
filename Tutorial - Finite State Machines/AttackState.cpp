#include "AttackState.h"
#include "Vector2.h"
#include "GameObject.h"
void AttackState::update(GameObject * gameObject, float deltaTime)
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
		target_dir = target_dir * m_speed;
		gameObject->addForce(target_dir);
	}
}
