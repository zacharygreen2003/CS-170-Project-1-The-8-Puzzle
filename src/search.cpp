// expand - tree
// frontier - in ggsa
// general generic search algorithm
// A* with euclidean search

#include "../include/node.h"
#include "../include/search.h"
//#include "../include/tree.h"


void fifoQF(std::vector<Node*>& frontier, const std::vector<Node*>& nodes) {
    for (int i = 0; i < nodes.size(); ++i) {
        frontier.push_back(nodes[i]);
    }
    /*cout << "---------" << endl;

    for (int i = 0; i < frontier.size(); ++i) {
        cout << endl;
        frontier[i]->GetPuzzle().printPuzzle();
    }
    cout << "---------" << endl;*/

}
void AStarEuclidean(std::vector<Node*>& frontier, const std::vector<Node*>& nodes) {
    // use nodes and compute the cost from the initial state which is add 1.
    // for each node in nodes compute the euclidean distance between where 0 is and where it should be in the goal state.

    for (int i = 0; i < nodes.size(); ++i) {
        nodes[i]->cost = 1 + nodes[i]->GetParent()->cost;
    }
    int x, y, goalx, goaly;
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
        nodes[i]->hueristic = sqrt(pow(goalx-x,2) + pow(goaly-y,2));
    }

    // NOT FINISHED

}


Node* generalSearch(Node* startNode, QueueingFunction queueFunction) {

    Puzzle p = startNode->GetPuzzle();

    vector<Node*> frontier(1, startNode);

    for (int i = 0; i < INT_MAX; ++i) {
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
        /*cout << "---------------" << endl;
        for (int i = 0; i < frontier.size(); ++i) {
            cout << endl;
            frontier[i]->GetPuzzle().printPuzzle();
        }
        cout << "---------------" << endl;*/


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