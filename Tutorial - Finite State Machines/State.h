#pragma once
#include <vector>
class GameObject;
class Transition;
class State
{
public:
	State();
	virtual ~State();


	virtual void update(GameObject* gameObject, float deltaTime) = 0;
	virtual void init(GameObject* gameObject) {};
	virtual void exit(GameObject* gameObject) {};

	void addTransition(Transition* transition) { m_transition.push_back(transition); }

	Transition* getTriggerdTransition(GameObject * gameObject);

protected:
	std::vector<Transition*> m_transition;
};

