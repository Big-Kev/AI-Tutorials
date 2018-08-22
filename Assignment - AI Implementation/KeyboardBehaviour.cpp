#include "KeyboardBehaviour.h"
#include "GameObject.h"



KeyboardBehaviour::KeyboardBehaviour()
{
}


KeyboardBehaviour::~KeyboardBehaviour()
{
}

eBehaviourResult KeyboardBehaviour::execute(GameObject * gameObject, float deltaTime)
{

	Vector2 dir(0,0);

	if (m_keys[0] == 1) {
		dir.y += 1;
	}

	if (m_keys[1] == 1) {
		dir.y -= 1;
	}

	if (m_keys[2] == 1) {
		dir.x -= 1;
	}

	if (m_keys[3] == 1) {
		dir.x += 1;
	}
	if (dir.x != 0 || dir.y != 0) {
		dir.normalise();
		gameObject->addForce(dir);
	}

	if (m_keys[0] == 0 && m_keys[1] == 0 && m_keys[2] == 0 && m_keys[3] == 0) {
		gameObject->decelerate(1);
	}

	return eBehaviourResult::SUCCESS;
}

void KeyboardBehaviour::getInput(aie::Input *key_in)
{

	m_keys[0] = 0;
	m_keys[1] = 0;
	m_keys[2] = 0;
	m_keys[3] = 0;

	if (key_in->isKeyDown(aie::INPUT_KEY_UP)) {
		m_keys[0] = 1;
	}
	if (key_in->isKeyDown(aie::INPUT_KEY_DOWN)) {
		m_keys[1] = 1;
	}
	if (key_in->isKeyDown(aie::INPUT_KEY_LEFT)) {
		m_keys[2] = 1;
	}
	if (key_in->isKeyDown(aie::INPUT_KEY_RIGHT)) {
		m_keys[3] = 1;
	}
}
