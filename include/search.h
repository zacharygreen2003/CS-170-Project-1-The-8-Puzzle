#ifndef SEARCH_H
#define SEARCH_H

typedef void (*QueueingFunction)(std::vector<Node*>&, const std::vector<Node*>&);
void fifoQF(std::vector<Node*>& frontier, const std::vector<Node*>& nodes);
void lifoQF(std::vector<Node*>& frontier, const std::vector<Node*>& nodes);
Node* generalSearch(Node* startNode, QueueingFunction queueFunction);

#endif