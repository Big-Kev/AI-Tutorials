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

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	//creating map
	b.ReadBMP("test.bmp", &o);
	graphMap.createGraph((getWindowWidth() / 40) - 1, (getWindowHeight() / 40) - 1, 40, 10, 10, &o);
	p1 = pathing1.aStareSearch((graphMap.getClosestNodePointer(100, 350)), (graphMap.getClosestNodePointer(800, 250)));
	pos = graphMap.getClosestNodePointer(200, 350)->getPos();

	//setting up behaviours
	m_pathEnemyBehaviour.setSpeed(10);
	m_enemy.setPosition(Vector2(100, 350));
	m_pathEnemyBehaviour.setPath(p1);
	m_enemy.addBehaviour(&m_pathEnemyBehaviour);
	m_player.addBehaviour(&m_playerBehaviour);


	return true;
}

void Assignment___AI_ImplementationApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Assignment___AI_ImplementationApp::update(float deltaTime) {


	m_enemy.update(deltaTime);


	// input example
	aie::Input* input = aie::Input::getInstance();

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
	m_2dRenderer->drawCircle(m_enemyImage.x, m_enemyImage.y, 10);

	m_player.getPosition(m_playerImage);
	m_2dRenderer->drawCircle(m_enemyImage.x, m_enemyImage.y, 10);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}