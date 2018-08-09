#include "Assignment___MapApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

Assignment___MapApp::Assignment___MapApp() {

}

Assignment___MapApp::~Assignment___MapApp() {

}

bool Assignment___MapApp::startup() {

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	b.bitmapTest((getWindowWidth() / 20) - 1, (getWindowHeight() / 20) - 1);
	graphMap.createGraph((getWindowWidth() / 20) - 1, (getWindowHeight() / 20) -1, 20, 10, 10);
	return true;
}

void Assignment___MapApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void Assignment___MapApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Assignment___MapApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	// draw your stuff here!
	graphMap.drawGraph(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}