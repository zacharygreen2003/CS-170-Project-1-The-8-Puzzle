#include "Astar.h"

Node::Node() {}

Node::Node(Puzzle puzzle, int cost, int heuristic)
    : board(puzzle), parent(nullptr), cost(cost), heuristic(heuristic) {}

Node::~Node() {
    // Clean up memory for children
    for (Node* child : children) {
        delete child;
    }
}

void Node::SetParent(Node* parentNode) {
    parent = parentNode;
}

void Node::SetChild(Node* childNode) {
    children.push_back(childNode);
}

int Node::GetNumChild() {
    return children.size();
}

Node* Node::GetChild(int index) {
    if (index >= 0 && index < children.size()) {
        return children[index];
    }
    return nullptr;
}

Node* Node::GetParent() {
    return parent;
}

Puzzle Node::GetPuzzle() {
    return board;
}
