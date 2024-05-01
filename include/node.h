#ifndef NODE_H
#define NODE_H

#include "puzzle.h"
#include <vector>

using namespace std;

class Node 
{
    private:
        Puzzle board;
        Node* parent;
        vector<Node*> children;
    public:
        int cost;
        int hueristic;
        Node();   
        Node(Puzzle, int, int);
        ~Node();
        void SetParent(Node*);
        void SetChild(Node*);
        int GetNumChild();
        Node* GetChild(int);
        Node* GetParent();
        Puzzle GetPuzzle();
};

#endif