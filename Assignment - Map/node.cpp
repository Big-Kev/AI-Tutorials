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
	//for (auto r : *nodeList) {
	//	for (auto n : r)
	//		if (n_pos.pythag(n.getPos()) < distance) {
	//			neighbours.push_back(&n);
	//		}
	//}
	//
	for (int o = 0; o > width; o++) {
		for (int i = 0; i > width; i++) {
			
			if (n_pos.pythag(nodeList[o][i].getPos()) < distance * distance) {
				neighbours.push_back(&nodeList[o][i]);
			}
		}
	}
}

void node::getGraphStats(graph * owner)
{

}

void node::drawNode(aie::Renderer2D * ren)
{


	//ren->drawBox(n_pos.x, n_pos.y, n_size, n_size);
	//ren->drawLine(n_pos.x, n_pos.y, n_pos.x + n_size, n_pos.y + n_size);
	ren->setRenderColour(1, 0, 0, 0.5);
	ren->drawLine(n_pos.x, n_pos.y, n_pos.x + n_size, n_pos.y);
	ren->drawLine(n_pos.x, n_pos.y, n_pos.x, n_pos.y + n_size);
	ren->setRenderColour(1, 1, 1, 0.5);

	drawRelations(ren);
	//ren->setRenderColour(1, 1, 1);
	//ren->drawBox(n_pos.x + 1, n_pos.y+1, n_size - 4, n_size -4);

}
void node::drawRelations(aie::Renderer2D * ren) {
	/*
	if (n_right != nullptr) {
		node* right = getRight();
		Vector2 r = right->getPos();
		ren->setRenderColour(0, 1, 0);
		ren->drawLine(n_pos.x + (n_size * 0.5) + 2, n_pos.y + (n_size * 0.5) - 2, r.x + (n_size * 0.5) - 2, r.y + (n_size * 0.5) - 2);
	}
	if (n_left != nullptr) {
		node* left = getLeft();
		Vector2 r = left->getPos();
		ren->setRenderColour(0, 0, 1);
		ren->drawLine(
	n_pos.x + (n_size * 0.5) + 2, n_pos.y + (n_size * 0.5) + 2, r.x + (n_size * 0.5) - 2, r.y + (n_size * 0.5) + 2);
	}*/
	for (node *n : neighbours) {
		ren->setRenderColour(0, 0, 1);
		ren->drawLine(n_pos.x, n_pos.y, n->getPos().x, n->getPos().y);

	}

}
