#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "graph.h"
#include "bitmap.h"

class Assignment___MapApp : public aie::Application {
public:

	Assignment___MapApp();
	virtual ~Assignment___MapApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	bitmap b;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	graph graphMap;
};