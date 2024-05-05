#ifndef NODE_H
#define NODE_H

#include "puzzle.h"
//#include "hashtable.h"
#include <vector>

class HashTable;

using namespace std;

class Node 
{
    private:
        Puzzle board;
        Node* parent;
        vector<Node*> children;
        static HashTable ht;
    public:
        int nodeID;
        static int counter;
        int cost;
        float hueristic;
        Node();   
        Node(Puzzle, int, int);
        ~Node();
        void SetParent(Node*);
        void SetChild(Node*);
        int GetNumChild();
        Node* GetChild(int);
        Node* GetParent();
        Puzzle GetPuzzle();

        vector<Node*> expand();
        /*Tree* getTree();
        void setTree(Tree*);*/
};


#endif