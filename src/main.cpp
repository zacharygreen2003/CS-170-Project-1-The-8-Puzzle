#include <iostream>
#include "../include/node.h"
#include "../include/search.h"
#include "../include/tree.h"

using namespace std;

int main() {
    Puzzle puzzle = Puzzle::defaultPuzzle();

    Node* start = new Node(puzzle, 0, 0);
    Node* n = generalSearch(start,AStarEuclidean);
    //n->GetPuzzle().printPuzzle();

    return 0;
}