#include "AStarEuclidean.h"
#include "hashtable.h"
#include <queue>
#include <cmath>  // For std::sqrt and std::pow
#include <iostream>

struct NodeComparator {
    bool operator()(const Node* a, const Node* b) const {
        return (a->cost + a->hueristic) > (b->cost + b->hueristic); // Min-heap for total cost comparison
    }
};

// Heuristic function: Euclidean distance for each tile to its goal position
int euclideanDistanceHeuristic(const Puzzle& current) {
    const auto& currentBoard = current.getBoard();
    const auto& goalBoard = Puzzle::getGoalState();

    int distance = 0;
    for (int i = 0; i < currentBoard.size(); i++) {
        for (int j = 0; j < currentBoard[i].size(); j++) {
            int tile = currentBoard[i][j];
            if (tile != 0) {
                for (int k = 0; k < goalBoard.size(); k++) {
                    for (int l = 0; l < goalBoard[k].size(); l++) {
                        if (goalBoard[k][l] == tile) {
                            int dx = i - k;
                            int dy = j - l;
                            distance += std::sqrt(dx * dx + dy * dy);
                        }
                    }
                }
            }
        }
    }
    return distance;
}

Node* AStarEuclidean(Node* start) {
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> frontier;
    HashTable explored(100);
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
            std::cout << "Goal found!" << std::endl;
            std::cout << "To solve this problem the search algorithm expanded a total of " << nodesExpanded << " nodes." << std::endl;
            std::cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << std::endl;
            std::cout << "The depth of the goal node was " << current->cost << "." << std::endl;
            return current;
        }

        std::vector<Puzzle> successors = current->GetPuzzle().successors();
        for (const Puzzle& succ : successors) {
            int h = euclideanDistanceHeuristic(succ);
            Node* child = new Node(succ, current->cost + 1, h);
            if (!explored.Contains(succ)) {
                explored.Insert(succ);
                frontier.push(child);
                current->SetChild(child);
                child->SetParent(current);

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
