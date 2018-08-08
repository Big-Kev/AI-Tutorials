#include "Tutorial___Steering_BehavioursApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "vector2.h"
Tutorial___Steering_BehavioursApp::Tutorial___Steering_BehavioursApp() {

}

Tutorial___Steering_BehavioursApp::~Tutorial___Steering_BehavioursApp() {

}

bool Tutorial___Steering_BehavioursApp::startup() {

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);


	m_wanderEnemyBehaviour.setPeram(2, 2, 2);
	m_player.setSpeed(4);
	m_player.addBehaviour(&m_playerBehaviour);
	m_player.setPosition(Vector2(50, 50));

	m_enemy.addBehaviour(&m_enemyBehaviour);
	m_enemy.setPosition(Vector2(500, 500));

	//m_enemyBehaviour.setSteeringForce(&m_seekPlayerBehaviour);
	m_enemyBehaviour.setSteeringForce(&m_wanderEnemyBehaviour);
	//m_enemyBehaviour.setSteeringForce(&m_pursuePlayerBehaviour);
	m_pursuePlayerBehaviour.m_target = &m_player;
	
	m_fleePlayerBehaviour.m_target = &m_player;
	m_seekPlayerBehaviour.m_target = &m_player;
	return true;
}

void Tutorial___Steering_BehavioursApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Tutorial___Steering_BehavioursApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	m_playerBehaviour.getInput(input);

	m_player.update(deltaTime);
	m_enemy.update(deltaTime);


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Tutorial___Steering_BehavioursApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!

	m_player.getPosition(m_playerImage); m_2dRenderer->setRenderColour(0, 0, 1); m_2dRenderer->drawCircle(m_playerImage.x, m_playerImage.y, 10);
	m_enemy.getPosition(m_enemyImage); m_2dRenderer->setRenderColour(1, 0, 0,0.4f); m_2dRenderer->drawCircle(m_enemyImage.x, m_enemyImage.y, 10);
	m_2dRenderer->setRenderColour(1, 0, 0, 1); //m_2dRenderer->drawCircle(m_enemyImage.x, m_enemyImage.y, 200);
	Vector2 testVelocity;
	m_enemy.getVelocity(testVelocity);
	testVelocity = testVelocity * 200;
	//m_2dRenderer->drawLine(m_enemyImage.x, m_enemyImage.y, m_enemyImage.x + testVelocity.x, m_enemyImage.y + testVelocity.y, 1.0f, 1);
	//m_2dRenderer->drawLine(m_enemyImage.x, m_enemyImage.y, m_playerImage.x, m_playerImage.y, 1.0f, 1);
	m_2dRenderer->drawLine(m_enemyImage.x, m_enemyImage.y, m_enemyImage.x + testVelocity.x, m_enemyImage.y + testVelocity.y, 1.0f, 1);
	/*
	if (((m_enemyImage.x - m_playerImage.x)* (m_enemyImage.x - m_playerImage.x) + (m_enemyImage.y - m_playerImage.y) * (m_enemyImage.y - m_playerImage.y)) > 200 * 200) {
		m_enemyBehaviour.setSteeringForce(&m_seekPlayerBehaviour);
	}
	else {
		m_enemyBehaviour.setSteeringForce(&m_fleePlayerBehaviour);
	}
	*/
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}