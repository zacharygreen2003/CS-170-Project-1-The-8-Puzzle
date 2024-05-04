#include "../include/node.h"
//#include "../include/hashtable.h"

using namespace std;

HashTable Node::ht(100000);

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

Puzzle Node::GetPuzzle(){
    return board;
}

vector<Node*> Node::expand() {
    // should only expand to nodes that havent been discovered
    // needs the hash table here and once in search for the firstNode
    vector<Puzzle> puzzle = this->GetPuzzle().successors();
    vector<Node*> n;

    /*cout << "-------------" << endl;

    for (int i = 0; i < puzzle.size(); ++i) {
        cout << endl;
        puzzle[i].printPuzzle();
    }

    cout << "-------------" << endl;*/
    for (int i = 0; i < puzzle.size(); ++i) {
       /* cout << endl;
        puzzle[i].printPuzzle();*/
        if (!ht.Contains(puzzle[i])) {
            ht.Insert(puzzle[i]);
            n.push_back(new Node(puzzle[i], 0, 0));
        }
    }

    
    
    
    children = n;
    return n;
}