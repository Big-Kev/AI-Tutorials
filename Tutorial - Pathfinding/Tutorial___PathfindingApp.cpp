#include "Tutorial___PathfindingApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Tutorial___PathfindingApp::Tutorial___PathfindingApp() {

}

Tutorial___PathfindingApp::~Tutorial___PathfindingApp() {

}

bool Tutorial___PathfindingApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	b.ReadBMP("test.bmp", &o);
	graphMap.createGraph((getWindowWidth() / 40) - 1, (getWindowHeight() / 40) - 1, 40, 10, 10, &o);
	p1 = pathing1.dijkstrasSearch((graphMap.getClosestNodePointer(100, 350)), (graphMap.getClosestNodePointer(800, 250)));
	pos = graphMap.getClosestNodePointer(200, 350)->getPos();
	

	return true;
}

void Tutorial___PathfindingApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Tutorial___PathfindingApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE)){
		pos = p1.path.top();
		prevNodes.push_back(p1.path.top());
		p1.path.pop();
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Tutorial___PathfindingApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	m_2dRenderer->setRenderColour(1, 0, 0);
	// draw your stuff here!
	graphMap.drawGraph(m_2dRenderer);
	m_2dRenderer->drawCircle(pos.x, pos.y, 10);
	
	m_2dRenderer->drawCircle(graphMap.getClosestNodePointer(800, 250)->getPos().x, graphMap.getClosestNodePointer(800, 250)->getPos().y, 10);

	for (Vector2 v : prevNodes) {
		m_2dRenderer->drawCircle(v.x, v.y, 10);
	}
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}