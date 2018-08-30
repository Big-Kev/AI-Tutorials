#include "Assignment___AI_ImplementationApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Assignment___AI_ImplementationApp::Assignment___AI_ImplementationApp() {

}

Assignment___AI_ImplementationApp::~Assignment___AI_ImplementationApp() {

}

bool Assignment___AI_ImplementationApp::startup() {

	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	//creating map
	b.ReadBMP("test.bmp", &o);
	graphMap.createGraph((getWindowWidth() / 40) - 1, (getWindowHeight() / 40) - 1, 40, 10, 10, &o);
	pos = graphMap.getClosestNodePointer(200, 350)->getPos();

	Vector2 test(100, 350);
	//setting up behaviours
	m_player.setPosition(Vector2(810, 200));
	m_player.addBehaviour(&m_playerMovementBehaviour);
	m_playerMovementBehaviour.setSteeringForce(&m_playerKeyboard);
	m_player.addBehaviour(&m_playerMovementBehaviour);
	m_player.setSpeed(5);
	m_player.getPosition(m_playerImage);



	m_enemy.setPosition(Vector2(150, 350));
	m_enemy.addBehaviour(&m_pathEnemyBehaviour);
	m_enemy.setSpeed(1);
	m_enemy.getPosition(m_enemyImage);

	return true;
}

void Assignment___AI_ImplementationApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Assignment___AI_ImplementationApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();
	m_playerKeyboard.getInput(input);

	if (m_playerImage.pythag(m_enemyImage) < 300 * 300) {
		if (m_enemy.isIdle()) {
			m_enemy.addBehaviour(&m_pathEnemyBehaviour);
		}
		p1 = pathing1.aStareSearch(graphMap.getClosestNodePointer(m_enemyImage.x, m_enemyImage.y), graphMap.getClosestNodePointer(m_playerImage.x, m_playerImage.y));
		m_pathEnemyBehaviour.setPath(p1);

	}else{
		m_enemy.removeBehaviour();
	}


	m_player.update(deltaTime);
	m_enemy.update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Assignment___AI_ImplementationApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!'
	graphMap.drawGraph(m_2dRenderer);
	m_enemy.getPosition(m_enemyImage);
	m_2dRenderer->setRenderColour(1, 0, 0);
	m_2dRenderer->drawCircle(m_enemyImage.x, m_enemyImage.y, 10);

	std::stack<Vector2>  t;
	t = p1.path;
	for (int i = 0; i < p1.path.size(); i++) {
		m_2dRenderer->setRenderColour(0, 0, 1);
		m_2dRenderer->drawCircle(t.top().x, t.top().y, 10);
		t.pop();
	}


	std::cout << m_enemyImage.x << ", " << m_enemyImage.y << std::endl;
	graphMap.getClosestNodes(m_playerImage.x, m_playerImage.y, m_2dRenderer);
	graphMap.getClosestNodes(m_enemyImage.x, m_enemyImage.y, m_2dRenderer);
	m_player.getPosition(m_playerImage);
	m_2dRenderer->setRenderColour(0, 1, 0);
	m_2dRenderer->drawCircle(m_playerImage.x, m_playerImage.y, 10);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}