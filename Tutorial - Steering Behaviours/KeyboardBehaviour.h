#pragma once
#include "Behaviour.h"
#include "Input.h"


class KeyboardBehaviour :
	public Behaviour
{
public:
	KeyboardBehaviour();
	virtual ~KeyboardBehaviour();

	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime);

	void setSpeed(float speed) { m_speed = speed; }

	void setTarget(GameObject* gameObject) { m_target = gameObject; }

	void getInput(aie::Input *key_in);
	


private:
	float m_speed;
	GameObject* m_target;
	bool m_keys[4] = {0,0,0,0};

};


