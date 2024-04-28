#include "Tree.h"
#include <algorithm>  // For std::find

Tree::Tree() {}

Tree::~Tree() {
    clear();
}

void Tree::addNode(Node* node) {
    nodes.push_back(node);
}

void Tree::clear() {
    for (Node* node : nodes) {
        delete node;
    }
    nodes.clear();
}
