#include "DijkstrasSearch.h"



DijkstrasSearch::DijkstrasSearch()
{
}


DijkstrasSearch::~DijkstrasSearch()
{
}

Path DijkstrasSearch::dijkstrasSearch(node * startNode, node * endNode)
{
	std::vector<node*> openList;
	std::vector<node*> closedList;
	node* startNode;
	startNode->parent = nullptr;
	openList.push_back(startNode);

	while (openList.empty() == false) {
		node* currentNode;



	}

}
