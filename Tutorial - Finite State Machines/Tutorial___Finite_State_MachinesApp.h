#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "GameObject.h"
#include "KeyboardBehaviour.h"
#include "FiniteStateMachine.h"
#include "WithinRangeCondition.h"
#include "AttackState.h"
#include "Transition.h"
#include "IdleState.h"

class Tutorial___Finite_State_MachinesApp : public aie::Application {
public:

	Tutorial___Finite_State_MachinesApp();
	virtual ~Tutorial___Finite_State_MachinesApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	GameObject m_player;
	KeyboardBehaviour m_playerBehaviour;

	GameObject m_enemy;
	FiniteStateMachine m_enemyBehaviour;

	Vector2 m_playerImage;
	Vector2 m_enemyImage;

};