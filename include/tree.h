#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <vector>

class Tree {
public:
    Tree();
    ~Tree();
    void addNode(Node* node);
    void clear();  // Clear the tree, deleting all nodes

private:
    std::vector<Node*> nodes;  // Stores all nodes to manage memory
};

#endif // TREE_H
