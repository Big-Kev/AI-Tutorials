#include "node.h"
#include "graph.h"

node::node(Vector2 v, float size)
{
	n_pos = v;
	n_size = size;
}
node::node(float x, float y, float size)
{	
	n_pos.x = x;
	n_pos.y = y;
	n_size = size;
}
node::~node()
{
}

void node::getGraphStats(graph * owner)
{

}

void node::drawNode(aie::Renderer2D * ren)
{
	ren->setRenderColour(1, 0, 0);
	//ren->drawCircle(n_pos.x, n_pos.y, 10);

	//ren->drawBox(n_pos.x, n_pos.y, n_size, n_size);
	ren->drawLine(n_pos.x, n_pos.y, n_pos.x + n_size, n_pos.y + n_size);
	ren->drawLine(n_pos.x, n_pos.y, n_pos.x + n_size, n_pos.y);
	ren->drawLine(n_pos.x, n_pos.y, n_pos.x, n_pos.y + n_size);
	//ren->setRenderColour(1, 1, 1);
	//ren->drawBox(n_pos.x + 1, n_pos.y+1, n_size - 4, n_size -4);

}
