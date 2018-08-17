#include "AStarSearch.h"
#include <algorithm>


AStarSearch::AStarSearch()
{
}


AStarSearch::~AStarSearch()
{
}


Path AStarSearch::aStareSearch(node * startNode, node * endNode)
{
	std::vector<node*> openList;
	std::vector<node*> closedList;
	node* currentNode;
	node* dijkstraStart;
	startNode->parent = nullptr;
	startNode->gScore = 0;
	startNode->fScore = 0;
	startNode->hScore = 0;

	openList.push_back(startNode);

	while (openList.empty() == false) {
		std::sort(openList.begin(), openList.end());
		currentNode = openList[0];

		if (currentNode == endNode) {
			break;
		}

		openList.erase(openList.begin());
		closedList.push_back(currentNode);

		for (node::Edge e : currentNode->connections) {
			if (std::find(closedList.begin(), closedList.end(), e.target) == closedList.end()) {//checking if not in lcosed list 
																								//e.target->gScore = e.cost + currentNode->gScore;
				if (std::find(openList.begin(), openList.end(), e.target) == openList.end()) {//checking if not in lcosed list 
																							  //e.target->gScore = currentNode->gScore; 
					e.target->gScore = e.cost + currentNode->gScore;
					e.target->hScore = sqrt(e.target->getPos().pythag(endNode->getPos()));
					e.target->fScore = e.target->gScore + e.target->hScore;
					
					e.target->parent = currentNode;
					openList.push_back(e.target);
				}
				else if (currentNode->gScore < e.target->gScore) {
					//e.target->gScore = currentNode->gScore;
					e.target->gScore = e.cost + currentNode->gScore;
					e.target->hScore = sqrt(e.target->getPos().pythag(endNode->getPos()));
					e.target->fScore = e.target->gScore + e.target->hScore;
					e.target->parent = currentNode;
				}
			}
		}
	}


	Path p;//not a stack of vector 2s, but a stack of nodes
	currentNode = endNode;
	while (currentNode != nullptr) {
		p.path.push(currentNode->getPos());
		currentNode = currentNode->parent;
	}
	return p;
}
