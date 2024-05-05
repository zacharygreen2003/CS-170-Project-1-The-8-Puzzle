#include "UniformCostSearch.h"
#include "hashtable.h"
#include <queue>
#include <vector>
#include <iostream>

struct NodeComparator {
    bool operator()(const Node* a, const Node* b) const {
        return a->cost > b->cost; // Min-heap for cost comparison
    }
};

Node* UniformCostSearch(Node* start) {
    std::priority_queue<Node*, std::vector<Node*>, NodeComparator> frontier;
    frontier.push(start);
    HashTable explored(100);
    int nodesExpanded = 0;
    int maxQueueSize = 0;

    // Print initial expanding state with 'b' replacing '0'
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
            Node* child = new Node(succ, current->cost + 1, 0);
            if (!explored.Contains(succ)) {
                explored.Insert(succ);
                current->SetChild(child);
                child->SetParent(current);
                frontier.push(child);

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
