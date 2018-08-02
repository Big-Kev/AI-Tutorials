#include "FiniteStateMachine.h"
#include "State.h"
#include "Transition.h"


FiniteStateMachine::FiniteStateMachine()
{
}

eBehaviourResult FiniteStateMachine::execute(GameObject * gameObject, float deltaTime)
{
	if (m_currentState != nullptr) {
		Transition* transition = m_currentState->getTriggeredTransition(gameObject);

		if (transition != nullptr) {
			m_currentState->exit(gameObject);
			m_currentState = transition->getTargetState();
			m_currentState->init(gameObject);
		}

		m_currentState->update(gameObject, deltaTime);
		return eBehaviourResult::SUCCESS;
	}
	return eBehaviourResult::FAILURE;
	
}
