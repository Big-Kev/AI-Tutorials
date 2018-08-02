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

	void addTransition(Transition* transition) { m_transitions.push_back(transition); }

	Transition* getTriggeredTransition(GameObject * gameObject);

protected:
	std::vector<Transition*> m_transitions;
};

