#include "Tutorial___Finite_State_MachinesApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Tutorial___Finite_State_MachinesApp::Tutorial___Finite_State_MachinesApp() {

}

Tutorial___Finite_State_MachinesApp::~Tutorial___Finite_State_MachinesApp() {

}

bool Tutorial___Finite_State_MachinesApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_playerBehaviour.setSpeed(400);
	m_player.addBehaviour(&m_playerBehaviour);
	m_player.setPosition(Vector2(500, 500));

	m_enemy.addBehaviour(&m_enemyBehaviour);
	m_enemy.setPosition(Vector2(100, 100));


	//create new states
	auto attackState = new AttackState(&m_player, 150);
	auto idleState = new IdleState();

	auto withinRangeCondition = new WithinRangeCondition(&m_player, 200);

	auto toAttackTransition = new Transition(attackState, withinRangeCondition);

	idleState->addTransition(toAttackTransition);

	m_enemyBehaviour.addState(attackState);
	m_enemyBehaviour.addState(idleState);

	m_enemyBehaviour.addCondition(withinRangeCondition);
	m_enemyBehaviour.addTransition(toAttackTransition);

	m_enemyBehaviour.setCurrentState(idleState);
	return true;
}

void Tutorial___Finite_State_MachinesApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Tutorial___Finite_State_MachinesApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	m_playerBehaviour.getInput(input);


	m_player.update(deltaTime);
	m_enemy.update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Tutorial___Finite_State_MachinesApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_player.getPosition(m_playerImage); m_2dRenderer->setRenderColour(0, 0, 1); m_2dRenderer->drawCircle(m_playerImage.x, m_playerImage.y, 10);
	m_enemy.getPosition(m_enemyImage); m_2dRenderer->setRenderColour(1, 0, 0); m_2dRenderer->drawCircle(m_enemyImage.x, m_enemyImage.y, 10);



	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}