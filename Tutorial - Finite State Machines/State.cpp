#include "State.h"



State::State()
{
}


State::~State()
{
}

Transition* State::getTriggerdTransition(GameObject * gameObject)
{
	for (auto transition : m_transitions) {
		if (transition->hasTriggered(gameObject)) {
			return transition;
		}
	}
	return nullptr;
}
