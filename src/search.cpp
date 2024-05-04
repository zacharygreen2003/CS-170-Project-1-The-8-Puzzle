#include "../include/search.h"
Search::Search() {
    choice = 1;
    puzzle = Puzzle();
    allMoves = nullptr;
    initialState = new Node(puzzle, 0, 0);
    solution = nullptr;
}
Search::Search(const int userChoice, Puzzle userPuzzle){
    choice=1;
    userPuzzle=Puzzle();
    allMoves = nullptr;
    initialState = new Node(puzzle, 0, 0);
    solution = nullptr;
}

void Search::AlgorithmPick(){
    switch(choice){
        case 1:
            solution = UniformCostSearch(initialState);
            break;
        case 2:
            //solution = AStarMisplaced(initialState);
            break;
        case 3:
            //solution = AStarHeuristic(initialState);
            break;
        default:
            solution = UniformCostSearch(initialState);
    }
    FinalSolution();
}
void Search::FinalSolution(){
    int numMoves = 0;
    if(solution != nullptr)
    {
        vector<Node*> movesList = allMoves->ParentList(solution);
        Node* currNode;
        cout << "Here is the best path to the solution: " << endl;  
        for(int i = movesList.size() - 1; i >= 0; --i)
        {
            if(i == movesList.size() - 1){cout << "Initial state" << endl;}
            else{cout << "Move " << numMoves << endl;}
            numMoves++;
            movesList[i]->GetPuzzle().printPuzzle();
            cout << endl;
        }
        cout << "GOAL!!!" << endl;
    }
    else 
    {
        cout << "There is not path to the solution" << endl;
    }
}