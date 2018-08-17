#pragma once
#include "Vector2.h"
#include <vector>
#include "Renderer2d.h"



class graph;
class node
{
public:

	struct Edge {
		node* target;
		float cost;

		bool Edge::operator > (const Edge& other) const
		{
			return (cost> other.cost);
		};
		bool Edge::operator < (const Edge& other) const
		{
			return (cost < other.cost);
		};
	};


	node(Vector2 v, float size);
	node(float x, float y, float size);
	~node();
	Vector2 getPos() { return n_pos; }
	void setLeft(node* n) { n_left = n; }
	void setRight(node* n) { n_right = n; }
	void setUp(node* n) { n_up = n; }
	void setdown(node* n) { n_down = n; }
	bool isObstructed() { return obstructed; }
	void addNeighbour(node* other) { neighbours.push_back(other); }
	void toggleObstructed() { if (obstructed == true) { obstructed = false; } else { obstructed = true; }; };
	node* getRight() { return n_right; };
	node* getLeft() { return n_left; };
	node* getUp() { return n_up; };
	node* getDown() { return n_down; };
	void findNeighbours(std::vector<std::vector<node>> nodeList, int width, int height, float distance);
	void addConnections();
	void getGraphStats(graph* owner);
	void drawNode(aie::Renderer2D* ren);

	void drawRelations(aie::Renderer2D * ren);

	

	node* parent;
	float gScore;
	float hScore;
	float fScore;
	std::vector<node*> neighbours;
	std::vector<Edge> connections;
protected:
	bool obstructed = false;
	Vector2 n_pos;
	float n_size;
	node* n_left;
	node* n_right;
	node* n_up;
	node* n_down;
};

