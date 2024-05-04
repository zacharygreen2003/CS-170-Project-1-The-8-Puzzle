#include "../include/node.h"

using namespace std;

Node::Node()
{
    parent = nullptr;
    cost = 0;
    hueristic = 0;
}

Node::Node(Puzzle currBoard, int c, int h)
{
    board = currBoard;
    cost = c;
    hueristic = h;
    parent = nullptr;
}

Node::~Node() 
{
    for(Node* container : children)
    {
        delete container;
    }
}

void Node::SetParent(Node* par)
{
    parent = par;
}

void Node::SetChild(Node* child)
{
    Node* newChild = child;
    children.push_back(newChild);
}

int Node::GetNumChild()
{
    return children.size();
}

Node* Node::GetChild(int pos)
{
    if(pos >= children.size())
    {
        return children.back();
    }
    return children.at(pos);
}

Node* Node::GetParent()
{
    return parent;
}

int Node::ParentCost()
{
    if(parent == nullptr)
    {
        return 0;
    }
    return parent->cost;
}

Puzzle Node::GetPuzzle(){
    return board;
}