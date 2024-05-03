#ifndef ASTAR_H
#define ASTAR_H

#include "puzzle.h"
#include <vector>

class Node {
private:
    Puzzle board;
    Node* parent;
    std::vector<Node*> children;

public:
    int cost;
    int heuristic;
    
    Node();
    Node(Puzzle puzzle, int cost, int heuristic);
    ~Node();
    
    void SetParent(Node* parentNode);
    void SetChild(Node* childNode);
    int GetNumChild();
    Node* GetChild(int index);
    Node* GetParent();
    Puzzle GetPuzzle();
};

#endif // ASTAR_H
