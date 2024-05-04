//Currently being worked on by Donovan and Adwin
#include "../include/UniformCostSearch.h"
#include "../include/hashtable.h"
#include <queue>
#include <iostream>

using namespace std;

Node* UniformCostSearch(Node* s)
{
    int numExpandedNodes = 0;
    int maxQueueSize = 0;
    int traceChoice = 1;
    bool notRepeated = false;
    bool enableTrace = true;
    queue<Node*> moves;
    HashTable pMoves(20);
    Node* currNode = nullptr;

    cout << "Would you like to trace all expanded nodes? 1) Yes  2) No" << endl;
    cin >> traceChoice;
    if(traceChoice == 2)
    {
        cout << "Finding best solution. This may take a while." << endl;
        enableTrace = false;
    }
    moves.push(s);
    while(!moves.empty())
    {
        if(moves.size() > maxQueueSize)
        {
            maxQueueSize = moves.size();
        }
        currNode = moves.front();
        pMoves.Insert(currNode->GetPuzzle());
        numExpandedNodes++;

        if(enableTrace)
        {
        cout<<"The best state to expand with g(n) = "<<currNode->cost<<" and h(n) = "<<currNode->hueristic<<" is..." <<endl;
        currNode->GetPuzzle().printPuzzle();
        cout << "Expanding Node..." << endl << endl;
        }

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
            notRepeated = true;
            Node* next = new Node(succ[i],currNode->cost + 1, 0);
            if(pMoves.Contains(next->GetPuzzle()))
            {
                notRepeated = false;
            }
            if(notRepeated)
            {
                currNode->SetChild(next);
                next->SetParent(currNode);
                moves.push(next);
            }
        }
        moves.pop();
    }
    cout << "Failure..." << endl;
    currNode = nullptr;
    return currNode;
}