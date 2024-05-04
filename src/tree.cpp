#include "../include/tree.h"
#include <stack>

using namespace std;

//Helper Function for destructor
void DeleteTree(Node* n){
    if(!n)
    {
        return;
    }
    for(unsigned int i = 0; i < n->GetNumChild(); n++){
        DeleteTree(n->GetChild(i));
    }
    delete n;
}

//Constructors
Tree::Tree(){head=nullptr;}
Tree::Tree(Node* start){head = start;}

//Destructor
Tree::~Tree()
{
    if(head == nullptr)
    {
        delete head;
        return;
    }
    DeleteTree(head);
}

void Tree::SetHead(Node* start)
{
    head = start;
}

Node* Tree::GetHead()
{
    return head;
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

