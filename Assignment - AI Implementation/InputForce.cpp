#include "InputForce.h"



InputForce::InputForce()
{

}


InputForce::~InputForce()
{
}

Vector2 InputForce::getForce(GameObject * gameObject)
{
	Vector2 dir(0, 0);
	//bool noIn = true;
	if (input->isKeyDown(aie::INPUT_KEY_UP)) {
		dir.y += 1;
		//noIn = false;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN)) {
		dir.y -= 1;
		//noIn = false;
	}
	if (input->isKeyDown(aie::INPUT_KEY_LEFT)) {
		dir.x -= 1;
		//noIn = false;
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT)) {
		dir.x += 1;
		//noIn = false;
	}

	//dir.normalise();

	return dir;
}

void InputForce::getInput(aie::Input * key_in)
{
	input = key_in;
}

void InputForce::setKeyIn(aie::Input * k)
{
	//key_in = k;
}
