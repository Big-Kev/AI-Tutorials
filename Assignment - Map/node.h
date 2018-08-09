#pragma once
#include "Vector2.h"
#include "Renderer2d.h"
class graph;
class node
{
public:
	node(Vector2 v, float size);
	node(float x, float y, float size);
	~node();
	Vector2 getPos() { return n_pos; }
	void setLeft(node* n) { n_left = n; }
	void setRight(node* n) { n_right = n; }
	void setUp(node* n) { n_up = n; }
	void setdown(node* n) { n_down = n; }


	node* getRight() { return n_right; };
	node* getLeft() { return n_left; };
	node* getUp() { return n_up; };
	node* getDown() { return n_down; };

	void getGraphStats(graph* owner);
	void drawNode(aie::Renderer2D* ren);

	void drawRelations(aie::Renderer2D * ren);

protected:
	Vector2 n_pos;
	float n_size;
	node* n_left;
	node* n_right;
	node* n_up;
	node* n_down;
};

