#pragma once
#include "Behaviour.h"
#include <stack>
class PathBehaviour :
	public Behaviour
{
public:
	PathBehaviour();
	virtual ~PathBehaviour();

	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);

	void setSpeed(float speed) { m_speed = speed; }

	void setPath(Path path);
	

protected:
	std::stack<Vector2> m_path;
	float m_speed;
	GameObject* m_target;
	
};

