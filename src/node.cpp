#include "../include/node.h"
#include "../include/hashtable.h"

using namespace std;

HashTable Node::ht(100000);
int Node::counter = 0;

Node::Node()
{
    parent = nullptr;
    cost = 0;
    hueristic = 0;
    //
    counter++;
    nodeID = counter;
}

Node::Node(Puzzle currBoard, int c, int h)
{
    board = currBoard;
    cost = c;
    hueristic = h;
    parent = nullptr;
    ht.Insert(this);
    counter++;
    nodeID = counter;

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

Puzzle Node::GetPuzzle(){
    return board;
}

vector<Node*> Node::expand() {
    // should only expand to nodes that havent been discovered
    // needs the hash table here and once in search for the firstNode
    vector<Puzzle> puzzle = this->GetPuzzle().successors();
    vector<Node*> n;

    Node* newNode;

    char stop;
    printf("-------------\n");

    for (int i = 0; i < puzzle.size(); ++i) {

        if (!ht.Contains(puzzle[i])) {
            //printf("notfound\n");
            newNode = new Node(puzzle[i], 0, 0);
            newNode->SetParent(this);

            //printf("id: %i\n", newNode->nodeID);
            n.push_back(newNode);
            //puzzle[i].printPuzzle();

        }
        else {
            printf("DROPPED\n");
            Node* n = ht.Contains(puzzle[i]);
            printf("ID: %i\n", n->nodeID);
            // I need to append the node but I cant find it.
            //printf("found\n");
            //n.push_back(ht.Contains(puzzle[i]));
            //n.push_back(newNode);
            //printf("id: %i\n", newNode->nodeID);
            //puzzle[i].printPuzzle();
        }
    }
    
    children = n;
    return n;
}