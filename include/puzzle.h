#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>

using namespace std;

class Puzzle {
public:
    Puzzle();
    explicit Puzzle(const vector<vector<int>>& board); // Constructor for initializing with a board
    static Puzzle defaultPuzzle();              // Returns the default puzzle
    void setTile(int row, int col, int value);  // Sets the value of a tile
    int getTile(int row, int col) const;        // Gets the value of a tile
    bool isGoal() const;                        // Checks if the current puzzle is the goal state
    vector<Puzzle> successors() const;          // Generates successor puzzles

private:
    vector<vector<int>> board;                   // Represents the 3x3 puzzle board
    static const vector<vector<int>> goalState;  // The goal configuration of the puzzle
};

#endif // PUZZLE_H