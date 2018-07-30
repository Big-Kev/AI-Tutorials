#include "FollowBehaviour.h"
#include "GameObject.h"
//#include "Vector2.h"

FollowBehaviour::FollowBehaviour()
{
}


FollowBehaviour::~FollowBehaviour()
{
}

eBehaviourResult FollowBehaviour::execute(GameObject * gameObject, float deltaTime)
{
	
	if (m_target == nullptr) {
		return eBehaviourResult::FAILURE;
	}

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
		gameObject->translate(target_dir);
	}
	

	return eBehaviourResult::SUCCESS;

}
