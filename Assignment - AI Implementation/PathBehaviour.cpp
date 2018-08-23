#include "PathBehaviour.h"
#include "GameObject.h"
#include "AStarSearch.h"
#include "Vector2.h"


PathBehaviour::PathBehaviour()
{
}


PathBehaviour::~PathBehaviour()
{
}

eBehaviourResult PathBehaviour::execute(GameObject * gameObject, float deltaTime)
{
	Vector2 m_pos;
	gameObject->getPosition(m_pos);
	if (m_path.empty() == false) {//checking if path is not empty
		if (m_pos.pythag(m_path.top()) < m_speed) {//checking if next node is within one frames movment of gameObject
			Vector2 target_dir = m_path.top() - m_pos;
			target_dir.normalise();
			target_dir = target_dir * m_speed;
			gameObject->translate(target_dir);
		}
	}
	return eBehaviourResult::SUCCESS;
}

void PathBehaviour::setPath(Path path)
{
	m_path = path.path;
}
