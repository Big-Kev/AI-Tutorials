#include "graph.h"

graph::graph(float screenWidth, float screenHeight, float nSize)
{
	node_size = 10;

}

graph::graph()
{
	node_size = 10;
}

graph::~graph()
{
}

void graph::createGraph()
{
	node_start = new node(0, 0);
	node* current_node = node_start;
	for (int i = 0; i < 20; i++) {
		current_node->setRight(new node(i*node_size, 0));
		current_node = current_node->getRight();
	}
}

void graph::drawGraph(aie::Renderer2D * ren)
{
	node* current_node = node_start;
	for (int i = 0; i < 20; i++) {
		current_node->drawNode(ren);
		current_node = current_node->getRight();
	}
}
