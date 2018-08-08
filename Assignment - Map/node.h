#pragma once
#include "Vector2.h"
#include "Renderer2d.h"
class node
{
public:
	node(Vector2 v);
	node(float x, float y);
	~node();
	Vector2 getPos() { return n_pos; }
	void setLeft(node* n) { n_left = n; }
	void setRight(node* n) { n_right = n; }
	void setUp(node* n) { n_up = n; }
	void setdown(node* n) { n_down = n; }

	node* getRight() { return n_right; };

	void drawNode(aie::Renderer2D* ren);
protected:
	Vector2 n_pos;
	
	node* n_left;
	node* n_right;
	node* n_up;
	node* n_down;
};

