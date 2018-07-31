#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Tutorial___Steering_BehavioursApp : public aie::Application {
public:

	Tutorial___Steering_BehavioursApp();
	virtual ~Tutorial___Steering_BehavioursApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};