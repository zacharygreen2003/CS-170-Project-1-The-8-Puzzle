//Currently being worked on by Donovan and Adwin
#include "UniformCostSearch.h"
#include <queue>

using namespace std;

void UniformCostSearch(Puzzle board)
{
    queue<Node*> moves;
    Tree* movesTree;
    Node* currNode = nullptr;
    Node* start = new Node(board, 0, 0);
    moves.push(start);
    movesTree->SetHead(start);
    while(!moves.empty())
    {
        currNode = moves.front();
        if(currNode->GetPuzzle().isGoal())
        {
            return;
        }
        vector<Puzzle> succ;
        succ = currNode->GetPuzzle().successors();
        for(unsigned int i = 0; i < succ.size(); i++)
        {
            Node* next = new Node(succ[i],currNode->cost + 1, 0);
            currNode->SetChild(next);
            next->SetParent(currNode);
            moves.push(next);
        }
        moves.pop();
    }
    return;
}