#pragma once
#include "graph.h"
#include "node.h"
#include <vector>
#include <stack>

struct Path {
	//std::stack<node*> path;
	std::stack<Vector2> path;
};

class DijkstrasSearch
{
public:
	DijkstrasSearch();
	~DijkstrasSearch();

	Path dijkstrasSearch(node* startNode, node* endNode);
};

