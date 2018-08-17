#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Assignment___AI_ImplementationApp : public aie::Application {
public:

	Assignment___AI_ImplementationApp();
	virtual ~Assignment___AI_ImplementationApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};