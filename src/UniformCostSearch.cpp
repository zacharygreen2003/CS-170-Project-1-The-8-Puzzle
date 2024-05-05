#include "../include/UniformCostSearch.h"
#include "../include/hashtable.h"
#include <queue>
#include <vector>
#include <iostream>


Node* UniformCostSearch(Node* start) {
    std::queue<Node*> frontier;
    frontier.push(start);
    HashTable explored(20);
    int nodesExpanded = 0;
    int maxQueueSize = 0;
    int traceAnswer = 2;
    bool traceChoice = false;

    //enable or disable the trace
    std::cout << "Would you like to trace the expanded nodes? 1) Yes  2) No" << endl;
    cin >> traceAnswer;
    if(traceAnswer == 1){traceChoice = true;}

    // Print initial expanding state with 'b' replacing '0'
    std::cout << "Expanding state" << std::endl;
    start->GetPuzzle().printPuzzle();
    std::cout << std::endl;

    explored.Insert(start->GetPuzzle());
    while (!frontier.empty()) {
        Node* current = frontier.front();
        frontier.pop();
        nodesExpanded++;
        maxQueueSize = std::max(maxQueueSize, int(frontier.size()));

        if(traceChoice)
        {
            std::cout << "The best state to expand with g(n) = " << current->cost << " is..." << std::endl;
            current->GetPuzzle().printPuzzle();
            std::cout << "      Expanding this node..." << std::endl << std::endl;
        }

        if (current->GetPuzzle().isGoal()) {
            std::cout << "Goal!!!" << std::endl;
            std::cout << "To solve this problem the search algorithm expanded a total of " << nodesExpanded << " nodes." << std::endl;
            std::cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << std::endl;
            std::cout << "The depth of the goal node was " << current->cost << "." << std::endl << std::endl;
            return current;
        }

        std::vector<Puzzle> successors = current->GetPuzzle().successors();
        for (const Puzzle& succ : successors) {
            Node* child = new Node(succ, current->cost + 1, 0);
            if (!explored.Contains(succ)) 
            {
                explored.Insert(succ);
                current->SetChild(child);
                child->SetParent(current);
                frontier.push(child);
            } 
            else 
            {
                delete child;
            }
        }
    }

    std::cout << "To solve this problem the search algorithm expanded a total of " << nodesExpanded << " nodes." << std::endl;
    std::cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << std::endl;
    std::cout << "No solution found." << std::endl << std::endl;
    return nullptr;
}
