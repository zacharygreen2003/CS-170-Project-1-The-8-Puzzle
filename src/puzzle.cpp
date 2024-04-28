#include "Puzzle.h"
#include <iostream>
#include <algorithm>  // For std::swap

// Initialize the goal state statically as required
const vector<vector<int>> Puzzle::goalState = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

// Constructor initializes an empty puzzle
Puzzle::Puzzle() : board(3, vector<int>(3, 0)) {}

// Constructor that initializes the board with a given configuration
Puzzle::Puzzle(const vector<vector<int>>& initBoard) : board(initBoard) {}

// Return a default puzzle configuration
Puzzle Puzzle::defaultPuzzle() {
    return Puzzle({{1, 0, 3}, {4, 2, 6}, {7, 5, 8}});
}

// Set a specific tile's value
void Puzzle::setTile(int row, int col, int value) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        board[row][col] = value;
    } else {
        cerr << "Error: Attempt to access out of bounds index in Puzzle::setTile" << endl;
    }
}

// Retrieve a specific tile's value
int Puzzle::getTile(int row, int col) const {
    if (row >= 0 && row < 3 && col >= 0 && col < 3) {
        return board[row][col];
    } else {
        cerr << "Error: Attempt to access out of bounds index in Puzzle::getTile" << endl;
        return -1; // Return an invalid value indicating an error
    }
}

// Check if the current state is the goal state
bool Puzzle::isGoal() const {
    return board == goalState;
}

// Find successors by making all possible moves (sliding tiles)
vector<Puzzle> Puzzle::successors() const {
    vector<Puzzle> result;
    int zero_row, zero_col;

    // Find the position of the '0' (empty space)
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == 0) {
                zero_row = row;
                zero_col = col;
                break;
            }
        }
    }

    // Directions vectors for moving the empty space: up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Generate all possible states by moving the empty space
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
