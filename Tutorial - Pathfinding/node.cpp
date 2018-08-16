#include "node.h"
#include "graph.h"

node::node(Vector2 v, float size)
{
	n_pos = v;
	n_size = size;
	setRight(nullptr);
}
node::node(float x, float y, float size)
{
	n_pos.x = x;
	n_pos.y = y;
	n_size = size;
	setRight(nullptr);
	setLeft(nullptr);
}
node::~node()
{
}


void node::findNeighbours(std::vector<std::vector<node>> nodeList, int width, int height, float distance)
{
	for (int o = 0; o > width; o++) {
		for (int i = 0; i > width; i++) {
			
			if (n_pos.pythag(nodeList[o][i].getPos()) < distance * distance) {
				neighbours.push_back(&nodeList[o][i]);
			}
		}
	}
	addConnections();//adding neighbours to edge list
}

void node::addConnections()
{
	for (int i = 0; i < neighbours.size(); i++) {
		Edge e;
		e.cost = 1;
		e.target = neighbours[i];
		connections.push_back(e);
	}
}

void node::getGraphStats(graph * owner)
{

}

void node::drawNode(aie::Renderer2D * ren)
{


	//ren->drawLine(n_pos.x, n_pos.y, n_pos.x + n_size, n_pos.y);
	//ren->drawLine(n_pos.x, n_pos.y, n_pos.x, n_pos.y + n_size);
	//ren->setRenderColour(1, 1, 1, 0.5);
	drawRelations(ren);
	
}
void node::drawRelations(aie::Renderer2D * ren) {
	
	for (node *n : neighbours) {
		ren->setRenderColour(0, 0, 1);
		ren->drawLine(n_pos.x, n_pos.y, n->getPos().x, n->getPos().y);

	}

}
