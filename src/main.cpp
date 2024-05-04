// #include <bits/stdc++.h>

#include <iostream>
#include "../include/puzzle.h"
#include "../include/UniformCostSearch.h"
#include "../include/tree.h"
#include "../include/search.h"

using namespace std;

void printWelcomeMessage() {
    cout << "Welcome to zgree004 8 puzzle solver." << endl;
}

void printMenu() {
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
}

Puzzle getUserDefinedPuzzle() {
    Puzzle p;
    int tile;
    cout << "Enter your puzzle, use zero to represent the blank." << endl;

    // Array of strings for row descriptions
    const char* rowDescriptions[] = {"first", "second", "third"};

    // Loop over each row and prompt the user
    for (int i = 0; i < 3; ++i) {
        cout << "Enter the " << rowDescriptions[i] << " row, use space or tabs between numbers: ";
        for (int j = 0; j < 3; ++j) {
            cin >> tile;
            p.setTile(i, j, tile);
        }
    }
    return p;
}

void chooseSearch(int choice, Puzzle &puzzle){
    switch(choice){
        case 1:
            puzzle = Puzzle::defaultPuzzle();
            break;
        case 2:
            puzzle = getUserDefinedPuzzle();
            break;
        default:
            cerr<< "Invalid input, using default puzzle." << endl;
            puzzle = Puzzle::defaultPuzzle();
    }
}

void printAlgorithmChoice() {
    cout << "Enter your choice of algorithm" << endl;
    cout << "1. Uniform Cost Search" << endl;;
    cout << "2. A* with the Misplaced Tile heuristic" << endl;
    cout << "3. A* with the Euclidean distance heuristic" << endl;
}
int main() {
    printWelcomeMessage();
    printMenu();

    int choice;
    cin >> choice;
    Puzzle puzzle;
    
    chooseSearch(choice, puzzle);
    puzzle.printPuzzle();

    printAlgorithmChoice();
    cin >> choice;
    Search algorithmChoice(choice, puzzle);
    algorithmChoice.AlgorithmPick();
    return 0;
}