#pragma once
#include "node.h"
#include <vector>
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
	Vector2 start_loc;

	float node_diagonal_size;
	node* node_start;

	std::vector< std::vector<node> > nodes;
};

