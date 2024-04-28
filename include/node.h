#ifndef NODE_H
#define NODE_H

#include "Puzzle.h"

class Node {
public:
    Node(Puzzle state, Node* parent, int cost, int heuristic);
    ~Node();

    Puzzle state;       // Current puzzle state
    Node* parent;       // Pointer to the parent node
    int cost;           // Cost from start node to this node
    int heuristic;      // Estimated cost from this node to the goal

    int totalCost() const { return cost + heuristic; }  // For priority queueing
};

#endif // NODE_H
