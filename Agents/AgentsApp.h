#pragma once
#include "Application.h"
#include "Renderer2D.h"
#include "GameObject.h"
#include "FollowBehaviour.h"
#include "KeyboardBehaviour.h"
#include "frictionBehaviour.h"

class AgentsApp : public aie::Application {
public:

	AgentsApp();
	virtual ~AgentsApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	GameObject m_player;
	FollowBehaviour m_playerFollowBehaviour;
	
	GameObject m_enemy;
	FollowBehaviour m_enemyFollowBehaviour;

	KeyboardBehaviour m_playerControls;

	frictionBehaviour m_playerSlow;

	Vector2 m_playerImage;
	Vector2 m_enemyImage;
};