#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Bitmap.h"
#include "graph.h"
#include "DijkstrasSearch.h"
#include "Vector2.h"
#include <vector>
class Tutorial___PathfindingApp : public aie::Application {
public:

	Tutorial___PathfindingApp();
	virtual ~Tutorial___PathfindingApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	Bitmap b;
	objectList o;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	Vector2 pos;
	graph graphMap;
	DijkstrasSearch pathing1;
	Path p1;
	vector<Vector2> prevNodes;
};