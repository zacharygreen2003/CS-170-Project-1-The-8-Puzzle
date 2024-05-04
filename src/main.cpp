// #include <bits/stdc++.h>

#include <iostream>
#include "puzzle.h"

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

void printAlgorithmChoice() {
    cout << "Enter your choice of algorithm" << endl;
    cout << "1. Uniform Cost Search" << endl;;
    cout << "2. A* with the Misplaced Tile heuristic" << endl;
    cout << "3. A* with the Euclidean distance heuristic" << endl;
}

// SearchAlgorithm* getAlgorithm(int choice, const Puzzle& puzzle) {
//     switch (choice) {
//         case 1:
//             return new UniformCostSearch();
//         case 2:
//             return new AStarMisplacedTile();
//         case 3:
//             return new AStarEuclidean();
//         default:
//             std::cerr << "Invalid choice, using Uniform Cost Search by default.\n";
//             return new UniformCostSearch();
//     }
// }

int main() {
    printWelcomeMessage();
    printMenu();

    int choice;
    cin >> choice;
    Puzzle puzzle;

    if (choice == 1) {
        puzzle = Puzzle::defaultPuzzle();
    } else if (choice == 2) {
        puzzle = getUserDefinedPuzzle();
    } else {
        cerr << "Invalid input, using default puzzle." << endl;
        puzzle = Puzzle::defaultPuzzle();
    }

    puzzle.printPuzzle();

    printAlgorithmChoice();
    cin >> choice;
    // SearchAlgorithm* algorithm = getAlgorithm(choice, puzzle);

    // algorithm->solve(puzzle);

    // delete algorithm;  // Clean up the dynamically allocated memory
    return 0;
}