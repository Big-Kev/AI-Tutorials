#pragma once
#include "graph.h"
#include "node.h"
#include <vector>
#include <stack>

struct Path {
	//std::stack<node*> path;
	std::stack<Vector2> path;
};

class AStarSearch
{
public:
	AStarSearch();
	~AStarSearch();
	Path aStareSearch(node * startNode, node * endNode);
};

