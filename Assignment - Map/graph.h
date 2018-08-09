#pragma once
#include "node.h"
#include "Renderer2D.h"
class graph
{
public:
	graph(float Width, float Height, float nSize = -1);
	graph();
	~graph();
	void createGraph();
	void drawGraph(aie::Renderer2D* ren);
protected:
	float node_size;
	int graph_height;
	int graph_width;
	float node_diagonal_size;
	node* node_start;

};

