#pragma once
#include "node.h"
#include "Renderer2D.h"
class graph
{
public:
	graph(float screenWidth, float screenHeight, float nSize = -1);
	graph();
	~graph();
	void createGraph();
	void drawGraph(aie::Renderer2D* ren);
protected:
	float node_size;
	float node_diagonal_size;
	node* node_start;

};

