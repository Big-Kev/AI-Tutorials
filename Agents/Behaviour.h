#pragma once
//class GameObject;
class GameObject;

enum eBehaviourResult {
	SUCCESS,
	FAILURE,
	RUNNING
};

class Behaviour
{
public:
	//empty construct and destruct for base class
	Behaviour();
	virtual ~Behaviour();

	
	virtual eBehaviourResult execute(GameObject* gameObject, float deltaTime) = 0;

};

