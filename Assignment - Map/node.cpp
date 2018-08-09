#include "node.h"

node::node(Vector2 v)
{
	n_pos = v;
}
node::node(float x, float y)
{
	
	
	n_pos.x = x;
	n_pos.y = y;
}
node::~node()
{
}

void node::drawNode(aie::Renderer2D * ren)
{
	ren->setRenderColour(1, 0, 0);
	//ren->drawCircle(n_pos.x, n_pos.y, 10);

	ren->drawBox(n_pos.x, n_pos.y, 24, 24);
	ren->setRenderColour(1, 1, 1);
	ren->drawBox(n_pos.x + 0.5, n_pos.y+0.5, 22, 22);

}
