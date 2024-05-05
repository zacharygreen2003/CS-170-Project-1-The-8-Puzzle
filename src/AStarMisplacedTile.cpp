#include "../include/AStarMisplacedTile.h"
#include "../include/hashtable.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct NodeComparator {
    bool operator()(const Node* a, const Node* b) const {
        return (a->cost + a->hueristic) > (b->cost + b->hueristic);
    }
};

// Heuristic function: count of misplaced tiles
int misplacedTileHeuristic(const Puzzle& current) {
    const auto& currentBoard = current.getBoard();
    const auto& goalBoard = Puzzle::getGoalState();

    int misplaced = 0;
    for (int i = 0; i < currentBoard.size(); i++) {
        for (int j = 0; j < currentBoard[i].size(); j++) {
            if (currentBoard[i][j] != 0 && currentBoard[i][j] != goalBoard[i][j]) {
                misplaced++;
            }
        }
    }
    return misplaced;
}

Node* AStarMisplacedTile(Node* start) {
    priority_queue<Node*, vector<Node*>, NodeComparator> frontier;
    HashTable explored(100); // Hashtable to prevent re-exploring nodes
    frontier.push(start);

    int nodesExpanded = 0;
    int maxQueueSize = 0;

    int traceAnswer = 2;
    bool traceChoice = false;

    // Enable or disable the trace
    cout << "Would you like to trace the expanded nodes? 1) Yes  2) No" << endl;
    cin >> traceAnswer;
    if(traceAnswer == 1){traceChoice = true;}

    cout << "Expanding state" << endl;
    start->GetPuzzle().printPuzzle();
    cout << endl;

    while (!frontier.empty()) {
        Node* current = frontier.top();
        frontier.pop();

        nodesExpanded++;
        maxQueueSize = max(maxQueueSize, int(frontier.size()));

        if(traceChoice)
        {
            cout << "The best state to expand with g(n) = " << current->cost << " and h(n) = " << current->hueristic << " is..." << endl;
            current->GetPuzzle().printPuzzle();
            cout << "      Expanding this node..." << endl << endl;
        }

        if (current->GetPuzzle().isGoal()) {
            cout << "Goal!!!" << endl;
            cout << "To solve this problem the search algorithm expanded a total of " << nodesExpanded << " nodes." << endl;
            cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << endl;
            cout << "The depth of the goal node was " << current->cost << "." << endl;
            return current;
        }

        vector<Puzzle> successors = current->GetPuzzle().successors();
        for (const Puzzle& succ : successors) {
            int h = misplacedTileHeuristic(succ);
            Node* child = new Node(succ, current->cost + 1, h);
            if (!explored.Contains(succ)) {
                explored.Insert(succ);
                frontier.push(child);
                current->SetChild(child);
                child->SetParent(current);
            } else {
                delete child;
            }
        }
    }
    cout << "To solve this problem the search algorithm expanded a total of " << nodesExpanded << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << endl;
    cout << "No solution found." << endl;
    return nullptr;
}