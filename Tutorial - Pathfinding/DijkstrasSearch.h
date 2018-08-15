#pragma once
#include "graph.h"
#include "node.h"
#include <vector>
#include <stack>

struct Path {
	std::stack<node*> path
};

class DijkstrasSearch
{
public:
	DijkstrasSearch();
	~DijkstrasSearch();

	Path dijkstrasSearch(node* startNode, node* endNode);
};

