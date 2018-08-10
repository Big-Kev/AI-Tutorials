#pragma once
#include "node.h"
#include <vector>
#include "Renderer2D.h"
#include "objectList.h"
class graph{
public:
	graph(float Width, float Height, float nSize, float startX, float startY);
	graph();
	~graph();
	void createGraph(int Width, int Height, float nSize, float startX, float startY, objectList* olist);
	void mapFromVectors(objectList * olist);
	void drawGraph(aie::Renderer2D* ren);

	void getClosestNodes(float x, float y, aie::Renderer2D * ren);
protected:
	void initGraph(int Width, int Height, float nSize, float startX, float startY);
	void applyRelations();

	void applyRelationsByDist();

	float node_size;
	int graph_height;
	int graph_width;
	Vector2 start_loc;

	float node_diagonal_size;
	node* node_start;

	std::vector< std::vector<node> > nodes;
};

