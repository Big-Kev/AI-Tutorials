#include "AgentsApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
AgentsApp::AgentsApp() {

}

AgentsApp::~AgentsApp() {

}

bool AgentsApp::startup() {

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);


	m_playerFollowBehaviour.setSpeed(1);
	m_playerFollowBehaviour.setTarget(&m_enemy);

	m_enemyFollowBehaviour.setSpeed(1);
	m_enemyFollowBehaviour.setTarget(&m_player);
	m_playerControls.setTarget(&m_player);
	m_playerControls.setSpeed(1);
	m_player.setPosition(Vector2(500, 500));
	m_player.setSpeed(1);
	m_player.addBehaviour(&m_playerControls);
	m_enemy.addBehaviour(&m_enemyFollowBehaviour);
	
	//m_player.addBehaviour(&m_playerSlow);
	//m_playerSlow.setTarget(&m_player);
	//m_playerSlow.setSpeed(90);
	return true;
}

void AgentsApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void AgentsApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	m_playerControls.getInput(input);
	
	m_player.update(deltaTime); 
	m_enemy.update(deltaTime);
	Vector2 temp;
	m_player.getPosition(temp);
	std::cout << temp.x << " " << temp.y << std::endl;


	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	
}

void AgentsApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!


	m_player.getPosition(m_playerImage); m_2dRenderer->setRenderColour(0, 0, 1); m_2dRenderer->drawCircle(m_playerImage.x, m_playerImage.y, 10);
	m_enemy.getPosition(m_enemyImage); m_2dRenderer->setRenderColour(1, 0, 0); m_2dRenderer->drawCircle(m_enemyImage.x, m_enemyImage.y, 10);

	//m_2dRenderer->drawCircle(100, 100, 40);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
