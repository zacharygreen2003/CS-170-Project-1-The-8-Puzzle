#include "../include/puzzle.h"
#include <iostream>
#include <algorithm>

// Initialize the goal state statically as required
const vector<vector<int>> Puzzle::goalState = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

// Constructor that initializes an empty puzzle
Puzzle::Puzzle() : board(3, vector<int>(3, 0)) {}

// Constructor that initializes the user-defined puzzle
Puzzle::Puzzle(const vector<vector<int>>& initBoard) : board(initBoard) {}

// Default puzzle
Puzzle Puzzle::defaultPuzzle() {
    return Puzzle({{1, 0, 3}, {4, 2, 6}, {7, 5, 8}});
}

// Sets the value of a tile in the puzzle
void Puzzle::setTile(int row, int col, int value) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        board[row][col] = value;
    } else {
        cerr << "Error: Attempt to access out of bounds index in Puzzle::setTile" << endl;
    }
}

// Gets the value of a tile in the puzzle
int Puzzle::getTile(int row, int col) const {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        return board[row][col];
    } else {
        cerr << "Error: Attempt to access out of bounds index in Puzzle::getTile" << endl;
        return -1; // Indicates error
    }
}

// Checks if the current puzzle is the goal state.
bool Puzzle::isGoal() const {
    return board == goalState;
}

// Returns all possible successor puzzles from the current puzzle
vector<Puzzle> Puzzle::successors() const {
    vector<Puzzle> result;
    int zero_row, zero_col;

    // Locate the zero tile in the current board.
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == 0) {
                zero_row = row;
                zero_col = col;
                break;
            }
        }
    }

    // Generates all valid moves by swapping the empty tile with adjacent tiles
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (const auto& dir : directions) {
        int new_row = zero_row + dir.first;
        int new_col = zero_col + dir.second;
        if (new_row >= 0 && new_row < 3 && new_col >= 0 && new_col < 3) {
            Puzzle new_puzzle = *this;
            swap(new_puzzle.board[zero_row][zero_col], new_puzzle.board[new_row][new_col]);
            result.push_back(new_puzzle);
        }
    }

    return result;
}

// Prints the current puzzle
void Puzzle::printPuzzle() const {
    for (const auto& row : board) {
        for (const auto& tile : row) {
            cout << (tile == 0 ? "b " : to_string(tile) + " ");
        }
        cout << endl;
    }
}

// Returns the current puzzle
vector<vector<int>> Puzzle::getBoard() const {
    return board;
}

// Gets the goal state of the puzzle
const vector<vector<int>>& Puzzle::getGoalState() {
    return goalState;
}
