#include "../include/AStarMisplacedTile.h"
#include "../include/hashtable.h"
#include <queue>
#include <vector>
#include <iostream>

struct NodeComparator {
    bool operator()(const Node* a, const Node* b) const {
        return (a->cost + a->hueristic) > (b->cost + b->hueristic); // Min-heap for total cost comparison
    }
};

// Heuristic function: count of misplaced tiles
int misplacedTileHeuristic(const Puzzle& current) {
    const auto& currentBoard = current.getBoard(); // Ensure getBoard() is const-qualified
    const auto& goalBoard = Puzzle::getGoalState(); // Assuming getGoalState() is public and static

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
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> frontier;
    HashTable explored(100); // Hashtable to prevent re-exploring nodes
    frontier.push(start);

    int nodesExpanded = 0;
    int maxQueueSize = 0;

    std::cout << "Expanding state" << std::endl;
    start->GetPuzzle().printPuzzle();
    std::cout << std::endl;

    while (!frontier.empty()) {
        Node* current = frontier.top();
        frontier.pop();

        nodesExpanded++;
        maxQueueSize = std::max(maxQueueSize, int(frontier.size()));

        if (current->GetPuzzle().isGoal()) {
            std::cout << "Goal!!!" << std::endl;
            std::cout << "To solve this problem the search algorithm expanded a total of " << nodesExpanded << " nodes." << std::endl;
            std::cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << std::endl;
            std::cout << "The depth of the goal node was " << current->cost << "." << std::endl;
            return current;
        }

        std::vector<Puzzle> successors = current->GetPuzzle().successors();
        for (const Puzzle& succ : successors) {
            int h = misplacedTileHeuristic(succ);
            Node* child = new Node(succ, current->cost + 1, h);
            if (!explored.Contains(succ)) {
                explored.Insert(succ);
                frontier.push(child);
                current->SetChild(child);
                child->SetParent(current);

                // Print each potential state
                std::cout << "The best state to expand with g(n) = " << child->cost << " and h(n) = " << child->hueristic << " is..." << std::endl;
                child->GetPuzzle().printPuzzle();
                std::cout << "      Expanding this node..." << std::endl << std::endl;
            } else {
                delete child;
            }
        }
    }

    std::cout << "No solution found." << std::endl;
    return nullptr;
}