#include "../include/UniformCostSearch.h"
#include "../include/hashtable.h"
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

Node* UniformCostSearch(Node* start) {
    queue<Node*> frontier;
    frontier.push(start);
    HashTable explored(100);
    int nodesExpanded = 0;
    int maxQueueSize = 0;
    int traceAnswer = 2;
    bool traceChoice = false;

    //enable or disable the trace
    cout << "Would you like to trace the expanded nodes? 1) Yes  2) No" << endl;
    cin >> traceAnswer;
    if(traceAnswer == 1){traceChoice = true;}

    // Print initial expanding state with 'b' replacing '0'
    cout << "Expanding state" << endl;
    start->GetPuzzle().printPuzzle();
    cout << endl;

    explored.Insert(start->GetPuzzle());
    while (!frontier.empty()) {
        Node* current = frontier.front();
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

    cout << "To solve this problem the search algorithm expanded a total of " << nodesExpanded << " nodes." << endl;
    cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << "." << endl;
    cout << "No solution found." << endl;
    return nullptr;
}
