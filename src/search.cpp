// expand - tree
// frontier - in ggsa
// general generic search algorithm
// A* with euclidean search

#include "../include/search.h"


void fifoQF(std::vector<Node*>& frontier, const std::vector<Node*>& nodes) {

    printf("expand\n");
    for (int i = 0; i < nodes.size(); ++i) {
        printf("ID: %i\n", nodes[i]->nodeID);
        nodes[i]->GetPuzzle().printPuzzle();
        printf("*\n");
    }

    printf("ADDED\n");
    for (int i = 0; i < nodes.size(); ++i) {
        bool found = false;
        for (int j = 0; j < frontier.size(); ++j) {
            if (frontier[j] == nodes[i]) {
                found = true;
                break;
            }
        }
        if (!found) {
            printf("ID: %i\n", nodes[i]->nodeID);
            frontier.push_back(nodes[i]);
        }
    }
}
void AStarEuclidean(std::vector<Node*>& frontier, const std::vector<Node*>& nodes) {
    // use nodes and compute the cost from the initial state which is add 1.
    // for each node in nodes compute the euclidean distance between where 0 is and where it should be in the goal state.

    printf("expand\n");
    for (int i = 0; i < nodes.size(); ++i) {
        printf("ID: %i\n", nodes[i]->nodeID);
        nodes[i]->GetPuzzle().printPuzzle();
        printf("*\n");
    }
    for (int i = 0; i < nodes.size(); ++i) {
        if (nodes[i]->GetParent() != nullptr) {
            nodes[i]->cost = 1 + nodes[i]->GetParent()->cost;
        }
    }
    int x, y,goalx,goaly;
    for (int i = 0; i < nodes.size(); ++i) {
        for (int row = 0; row < 3; ++row){
            for (int col = 0; col < 3; ++col) {
                if (nodes[i]->GetPuzzle().getTile(row, col) == 0) {
                    x = row;
                    y = col;
                }
                if (nodes[i]->GetPuzzle().goalState[row][col] == 0) {
                    goalx = row;
                    goaly = col;
                }
            }
        }
        //nodes[i]->GetPuzzle().printPuzzle();
        //printf("x: %i, y: %i, gx: %i, gy: %i\n", x, y, goalx, goaly);
        //printf("heuristic: %f\n", sqrt(pow(goalx - x, 2) + pow(goaly - y, 2)));
        nodes[i]->hueristic = sqrt(pow(goalx-x,2) + pow(goaly-y,2));
    }

    printf("ADDED\n");
    for (int i = 0; i < nodes.size(); ++i) {
        int place = frontier.size();
        for (int j = 0; j < frontier.size(); ++j) {
            if (nodes[i]->cost + nodes[i]->hueristic <= frontier[j]->cost + frontier[j]->hueristic) {
                place = j;
                break;
            }
        }
        printf("ID: %i\n",nodes[i]->nodeID);
        printf("at: %i\n", place);
        frontier.insert(frontier.begin() + place, nodes[i]);
    }

}

Node* generalSearch(Node* start, QueueingFunction queueFunction) {

    vector<Node*> frontier(1, start);

    for (int i = 0; i < INT_MAX; ++i) {

        printf("frontier\n");
        cout << frontier.size() << endl;
        for (int j = 0; j < frontier.size(); ++j) {
            printf("ID: %i\n", frontier[j]->nodeID);
            printf("C: %i\n", frontier[j]->cost);
            printf("H: %f\n", frontier[j]->hueristic);
            printf("F: %f\n", frontier[j]->cost + frontier[j]->hueristic);

            frontier[j]->GetPuzzle().printPuzzle();
            printf("*\n");
        }

        if (frontier.empty()) {
            // failure
            return nullptr;
        }
        Node* node = frontier.front();
        frontier.erase(frontier.begin());
        if (node->GetPuzzle().isGoal()) {
            return node;
        }
        queueFunction(frontier, node->expand());
        
    }
     return frontier[0];
}

/*function general - search(problem, queueFunction)
frontier = queueFunction(makeNode(problem.initialState))
loop do
    if EMPTY(frontier) then return "failure"
        node = removeFront(nodes)
    if problem.testGoal(node.STATE) then return node
        frontier = queueFunction(frontier, EXPAND(node, problem.OPERATORS))
end*/