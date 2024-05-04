#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <vector>

using namespace std;

class Tree 
{
    private:
        Node* head;
    public:
        Tree();
        Tree(Node*);
        ~Tree();
        void SetHead(Node*);
        Node* GetHead();
        vector<Node*> ParentList(Node*);
};


#endif