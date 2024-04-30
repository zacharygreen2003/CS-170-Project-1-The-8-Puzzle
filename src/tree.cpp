#include "../include/tree.h"

using namespace std;

Tree::Tree(){head=nullptr;}
Tree::Tree(Node* start){head = start;}

void Tree::SetHead(Node* start)
{
    head = start;
}

vector<Node*> Tree::ParentList(Node* child)
{
    vector<Node*> parents;
    Node* currNode = child;
    while(currNode != nullptr)
    {
        parents.push_back(currNode);
        currNode = currNode->GetParent();
    }
    return parents;
}

bool Tree::Contains(Node* child)
{
    if(child == nullptr){}
}

bool TreeSearch(Node* curr, Node* Sol)
{
    if(curr == nullptr)
    {
        return false;
    }
    if(curr->GetPuzzle() == Sol->GetPuzzle())
    {
        return true;
    }
    for(unsigned int i = 0; i < curr->GetNumChild(); i++)
    {
        bool foundChild = TreeSearch(curr->GetChild(i), Sol);
        if(foundChild)
        {
            return foundChild;
        }
    }
    return false;
}