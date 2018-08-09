#include "graph.h"

graph::graph(float Width, float Height, float nSize)
{
	graph_width = Width;
	graph_height = Height;

}

graph::graph()
{
	node_size = 22;
	graph_width = 20;
	graph_height = 20;
}

graph::~graph()
{
}

void graph::createGraph()
{
	node_start = new node(50, 50);
	node* current_node = node_start;
	for (int i = 0; i < graph_width; i++) {
		current_node->setRight(new node(i*node_size + 50, 50));
		current_node = current_node->getRight();
	}
}

void graph::drawGraph(aie::Renderer2D * ren)
{
	node* current_node = node_start;
	for (int i = 0; i < graph_width; i++) {
		current_node->drawNode(ren);
		current_node = current_node->getRight();
	}
}
