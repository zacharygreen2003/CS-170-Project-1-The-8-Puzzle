#include "Node.h"

Node::Node(Puzzle state, Node* parent, int cost, int heuristic)
    : state(state), parent(parent), cost(cost), heuristic(heuristic) {}

Node::~Node() {

}
