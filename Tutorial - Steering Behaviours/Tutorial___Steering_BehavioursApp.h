#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "GameObject.h"
#include "KeyboardBehaviour.h"
#include "SteeringBehaviour.h"
#include "SeekForce.h"
#include "FleeForce.h"
class Tutorial___Steering_BehavioursApp : public aie::Application {
public:

	Tutorial___Steering_BehavioursApp();
	virtual ~Tutorial___Steering_BehavioursApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;


	GameObject			m_player;
	KeyboardBehaviour	m_playerBehaviour;

	GameObject			m_enemy;
	SteeringBehaviour	m_enemyBehaviour;
	SeekForce			m_seekPlayerBehaviour;
	FleeForce			m_fleePlayerBehaviour;
	Vector2				m_playerImage;
	Vector2				m_enemyImage;
};