#include "graph.h"

graph::graph(float Width, float Height, float nSize, float startX, float startY)
{
	graph_width = Width;
	graph_height = Height;
	node_size = nSize;
	start_loc.x = startX;
	start_loc.y = startY;

}
void graph::initGraph(int Width, int Height, float nSize, float startX, float startY)
{
	graph_width = Width;
	graph_height = Height;
	node_size = nSize;
	start_loc.x = startX;
	start_loc.y = startY;

}

void graph::applyRelations()
{
	for (int i = 0; i < graph_height; i++) {
		nodes[i][0].setRight(&nodes[i][1]);
		nodes[i][1].setLeft(&nodes[i][0]);
		for (int o = 1; o < graph_width - 1; o++) {
			nodes[i][o].setRight(&nodes[i][o + 1]);
			nodes[i][o + 1].setLeft(&nodes[i][o]);
		}
	}
}

void graph::applyRelationsByDist()
{
	for (int i = 0; i < graph_height; i++) {
		for (int o = 0; o < graph_width; o++) {
			//
		}
	}
	nodes[21][21].findNeighbours(nodes, 1, 1, 50);
}

graph::graph()
{
	//node_size = 22;
	//graph_width = 20;
	//graph_height = 20;
	//start_loc.x = 20;
	//start_loc.y = 20;
}

graph::~graph()
{
}


void graph::createGraph(int Width, int Height, float nSize, float startX, float startY)
{
	/*
	node_start = new node(50, 50);
	node* current_node = node_start;
	for (int i = 0; i < graph_width; i++) {
		current_node->setRight(new node(i*node_size + 50, 50));
		current_node = current_node->getRight();
	}*/
	initGraph(Width, Height, nSize, startX, startY);
	for (int i = 0; i < graph_height; i++) {
		std::vector<node> v;
		nodes.push_back(v);
		for (int o = 0; o < graph_width; o++) {
			nodes[i].push_back(node(((node_size * o) + start_loc.x), (node_size * i) + start_loc.y, node_size));
		}
	}
	mapFromVectors();
	//applyRelations();
	//applyRelationsByDist();
	float distance = 30;
	for (int i = 0; i < graph_height; i++) {
		for (int o = 0; o < graph_width; o++) {
			for (int a = 0; a < graph_height; a++) {
				for (int b = 0; b < graph_width; b++) {
					if (nodes[i][o].getPos().pythag(nodes[a][b].getPos()) < distance * distance) {
						if (nodes[i][o].isObstructed() == false && nodes[a][b].isObstructed() == false) {
							nodes[i][o].addNeighbour(&nodes[a][b]);
						}
					}
				}
			}
		}
	}

}
void graph::mapFromVectors() {
	std::vector<Vector2> v;
	v.push_back(Vector2(2, 3));
	v.push_back(Vector2(2, 4));
	v.push_back(Vector2(2, 5));
	v.push_back(Vector2(3, 5));
	v.push_back(Vector2(2, 6));
	v.push_back(Vector2(2, 7));
	v.push_back(Vector2(12, 3));
	v.push_back(Vector2(22, 14));
	v.push_back(Vector2(22, 15));
	v.push_back(Vector2(23, 15));
	v.push_back(Vector2(22, 6));
	v.push_back(Vector2(2, 7));
	for (int i = 0; i < graph_height; i++) {
		for (int o = 0; o < graph_width; o++) {
			for (int x = 0; x < v.size(); x++) {
				if (v[x].x == o && v[x].y == i) {
					nodes[i][o].toggleObstructed();
				}
			}
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

	for (int i = 0; i < graph_height; i++) {
		for (int o = 0; o < graph_width; o++) {
			nodes[i][o].drawNode(ren);
		}
	}

	//for (int i = 0; i < graph_height-2; i++) {
		//for (node n : nodes[0]) {
		//	n.drawNode(ren);

			//}

}
