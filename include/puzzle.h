#ifndef PUZZLE_H
#define PUZZLE_H

#include <vector>
#include <iostream>

using namespace std;

class Puzzle {
public:
    Puzzle();
    explicit Puzzle(const vector<vector<int>>& board);
    static Puzzle defaultPuzzle();
    void setTile(int row, int col, int value);
    int getTile(int row, int col) const;
    bool isGoal() const;
    vector<Puzzle> successors() const;
    void printPuzzle() const; // Add this line to declare the function
    vector<vector<int>> getBoard() const;
    static const vector<vector<int>>& getGoalState();

private:
    vector<vector<int>> board;
    static const vector<vector<int>> goalState;
};

#endif // PUZZLE_H
