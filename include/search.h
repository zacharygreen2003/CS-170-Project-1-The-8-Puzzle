#ifndef SEARCH_H
#define SEARCH_H

#include "../include/node.h"

typedef void (*QueueingFunction)(std::vector<Node*>&, const std::vector<Node*>&);
void fifoQF(std::vector<Node*>& frontier, const std::vector<Node*>&);
void AStarEuclidean(std::vector<Node*>& frontier, const std::vector<Node*>&);
Node* generalSearch(Node* startNode, QueueingFunction queueFunction);

#endif