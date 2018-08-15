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


void graph::createGraph(int Width, int Height, float nSize, float startX, float startY, objectList* olist)
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
	mapFromVectors(olist);
	//applyRelations();
	//applyRelationsByDist();


	float distance = 60;
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
void graph::mapFromVectors(objectList* olist) {



	for (int h = 0; h < graph_height; h++) {
		for (int x = 0; x < graph_width; x++) {
			int temp = graph_width * h + x;
			if (olist->data[temp].x >= 100) {
				nodes[h][x].toggleObstructed();
			}
		}
	}
	/*
	for (int i = 0; i < graph_height; i++) {
		for (int o = 0; o < graph_width; o++) {
			for (int x = 0; x < olist->data.size(); x++) {
				if (olist->data[x].x == o && olist->data[x].y == i && olist->data[x].y >= 1) {
					nodes[i][o].toggleObstructed();
				}
			}
		}
	}
	*/

}


void graph::drawGraph(aie::Renderer2D * ren)
{
	for (int i = 0; i < graph_height; i++) {
		for (int o = 0; o < graph_width; o++) {
			nodes[i][o].drawNode(ren);
		}
	}
}

void graph::getClosestNodes(float x, float y, aie::Renderer2D * ren)
{
	int n = 1;
	std::vector<node*> nearbyNodes;
	node* close;
	for (int i = 0; i < n; i++) {
		int xnode = x / 40;
		int ynode = y / 40;
		close = &nodes[ynode][xnode];
		//nearbyNodes.push_back(close);
	}

	ren->setRenderColour(0, 1, 1);
	ren->drawLine(x, y, close->getPos().x, close->getPos().y);
	ren->drawCircle(x, y, 10);



	for (node *copynode : close->neighbours) {
		nearbyNodes = close->neighbours;
	}


	for (int i = 0; i < nearbyNodes.size(); i++) {
		ren->drawLine(x, y, nearbyNodes[i]->getPos().x, nearbyNodes[i]->getPos().y);
		
	}




	//nodes[x][y].getPos().x
}
