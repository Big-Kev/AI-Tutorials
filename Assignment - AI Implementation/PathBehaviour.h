#pragma once
#include "Behaviour.h"

class PathBehaviour :
	public Behaviour
{
public:
	PathBehaviour();
	virtual ~PathBehaviour();

	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);

	void setSpeed(float speed) { m_speed = speed; }

	void setPath(Path& path) { m_path = path; }


private:
	Path m_path;
	float m_speed;
	GameObject* m_target;
	
};

