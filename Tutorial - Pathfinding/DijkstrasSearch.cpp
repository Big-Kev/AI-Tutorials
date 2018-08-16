#include "DijkstrasSearch.h"
#include <algorithm>
struct Edge;

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
	node* currentNode;
	node* dijkstraStart;
	startNode->parent = nullptr;
	startNode->gScore = 0;
	openList.push_back(startNode);

	while (openList.empty() == false) {
		std::sort(openList.begin(), openList.end());
		currentNode = openList[0];

		if (currentNode == endNode) {
			continue;
		}

		openList.erase(openList.begin());
		closedList.push_back(currentNode);

		for (node::Edge e : currentNode->connections) {
			if (std::find(closedList.begin(), closedList.end(), e.target) == closedList.end()) {//checking if not in lcosed list 
				e.target->gScore = e.cost + currentNode->gScore;
				if (std::find(openList.begin(), openList.end(), e.target) == openList.end()) {//checking if not in lcosed list 
					e.target->gScore = currentNode->gScore; // WUT?? is gscore refering to current node gscore
					e.target->parent = currentNode;
					openList.push_back(e.target);
				}
				else if (currentNode->gScore < e.target->gScore) {
					e.target->gScore = currentNode->gScore;
					e.target->parent = currentNode;
				}
			}
		}
	}
}
