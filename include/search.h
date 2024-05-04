#ifndef SEARCH_H
#define SEARCH_H

#include "puzzle.h"
#include "node.h"
#include "tree.h"
#include "UniformCostSearch.h"

class Search {
public:
    Search();
    Search(const int userChoice, Puzzle userPuzzle);
    void AlgorithmPick();
    void FinalSolution();
private:
    int choice;
    Puzzle puzzle;
    Tree* allMoves;
    Node* initialState;
    Node* solution;
};
#endif //SEARCH_H