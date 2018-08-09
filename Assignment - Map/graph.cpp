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
	start_loc.x = 20;
	start_loc.y = 20;
}

graph::~graph()
{
}

void graph::createGraph()
{
	/*
	node_start = new node(50, 50);
	node* current_node = node_start;
	for (int i = 0; i < graph_width; i++) {
		current_node->setRight(new node(i*node_size + 50, 50));
		current_node = current_node->getRight();
	}*/
	
	for (int i = 0; i < graph_width; i++) {
		std::vector<node> v;
		nodes.push_back(v);
		for (int o = 0; o < graph_width; o++) {
			nodes[i].push_back(node(((node_size * o) + start_loc.x), (node_size * i) + start_loc.y));
		}
	}


}

void graph::drawGraph(aie::Renderer2D * ren)
{
	/*
	node* current_node = node_start;
	for (int i = 0; i < graph_width; i++) {
		current_node->drawNode(ren);
		current_node = current_node->getRight();
	}*/
	for (int i = 0; i < graph_width; i++) {
		for (int o = 0; o < graph_width -1; o++) {
			nodes[i][o].drawNode(ren);
		}
	}


}
