#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "AStarSearch.h"
#include "GameObject.h"
#include "Bitmap.h"
#include "PathBehaviour.h"
#include "KeyboardBehaviour.h"
#include <vector>
#include "SteeringBehaviour.h"
#include "InputForce.h"
#include "MoveToForce.h"

class Assignment___AI_ImplementationApp : public aie::Application {
public:

	Assignment___AI_ImplementationApp();
	virtual ~Assignment___AI_ImplementationApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	Bitmap				b;
	objectList			o;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	Vector2				pos;
	graph				graphMap;
	AStarSearch			pathing1;
	Path				p1;
	std::vector<Vector2> prevNodes;
	PathBehaviour		aStarTest;

	GameObject			m_player;
	SteeringBehaviour	m_playerMovementBehaviour;
	MoveToForce			m_playerSteering;
	InputForce			m_playerKeyboard;

	GameObject			m_enemy;
	//SeekForce			m_seekPlayerBehaviour;
	//FleeForce			m_fleePlayerBehaviour;
	//PursueForce		m_pursuePlayerBehaviour;
	//WanderForce		m_wanderEnemyBehaviour;
	PathBehaviour		m_pathEnemyBehaviour;

	Vector2				m_playerImage;
	Vector2				m_enemyImage;
};