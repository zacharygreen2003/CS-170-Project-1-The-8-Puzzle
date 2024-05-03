//Currently being worked on by Donovan and Adwin
#include "../include/UniformCostSearch.h"
#include <queue>
#include <iostream>

using namespace std;

Node* UniformCostSearch(Puzzle board,Tree* movesTree, Node* s)
{
    int numExpandedNodes = 0;
    int maxQueueSize = 0;

    bool repeated = false;
    queue<Node*> moves;
    vector<Node*> pastMoves;
    Node* currNode = nullptr;
    //Node* start = new Node(board, 0, 0);
    moves.push(s);
    //movesTree->SetHead(start);
    while(!moves.empty())
    {
        if(moves.size() > maxQueueSize)
        {
            maxQueueSize = moves.size();
        }
        currNode = moves.front();
        numExpandedNodes++;
        cout<<"The best state to expand with g(n) = "<<currNode->cost<<" and h(n) = "<<currNode->hueristic<<" is..." <<endl;
        currNode->GetPuzzle().printPuzzle();
        cout << "Expanding Node..." << endl << endl;
        if(currNode->GetPuzzle().isGoal())
        {
            cout << "GOAL!!!" << endl << endl;
            cout << "To solve this proble the algorithm expanded a total of " << numExpandedNodes << " nodes" << endl;
            cout << "The maximum number of nodes in the queue at any one time: " << maxQueueSize << endl;
            cout << "The depth of the goal node was " << currNode->cost << endl << endl;
            return currNode;
        }
        vector<Puzzle> succ;
        succ = currNode->GetPuzzle().successors();
        for(unsigned int i = 0; i < succ.size(); i++)
        {
            repeated = true;
            Node* next = new Node(succ[i],currNode->cost + 1, 0);
            for(unsigned int j = 0; j < pastMoves.size(); j++)
            {
                if(pastMoves[j]->GetPuzzle().getBoard() == next->GetPuzzle().getBoard())
                {
                   repeated = false; 
                }
            }
            if(repeated)
            {
                currNode->SetChild(next);
                next->SetParent(currNode);
                moves.push(next);
                pastMoves.push_back(next);
            }
        }
        moves.pop();
    }
    cout << "Failure..." << endl;
    currNode = nullptr;
    return currNode;
}