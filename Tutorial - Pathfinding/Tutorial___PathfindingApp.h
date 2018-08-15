#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Tutorial___PathfindingApp : public aie::Application {
public:

	Tutorial___PathfindingApp();
	virtual ~Tutorial___PathfindingApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};