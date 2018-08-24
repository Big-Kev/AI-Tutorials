#pragma once
#include "SteeringForce.h"
#include "input.h"
#include <iostream>
class InputForce :
	public SteeringForce
{
public:
	InputForce();
	~InputForce();

	Vector2 getForce(GameObject* gameObject);

	void getInput(aie::Input *key_in);
	void setKeyIn(aie::Input *k);
	GameObject * m_target;
	
	aie::Input * input;
};

