// #include "AStarEuclidean.h"
// #include <cmath>
// #include <iostream>

// int AStarEuclidean::calculateEuclideanDistance(const Puzzle& current, const Puzzle& goal) const {
//     int distance = 0;
//     for (int i = 0; i < 3; ++i) {
//         for (int j = 0; j < 3; ++j) {
//             int tile = current.getTile(i, j);
//             if (tile != 0) {
//                 for (int m = 0; m < 3; ++m) {
//                     for (int n = 0; n < 3; ++n) {
//                         if (goal.getTile(m, n) == tile) {
//                             distance += std::sqrt((i - m) * (i - m) + (j - n) * (j - n));
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     return distance;
// }

// Node* AStarEuclidean::search(Node* initial) {
//     addToFrontier(initial);
    
//     while (!isFrontierEmpty()) {
//         Node* node = removeFromFrontier();
//         nodesExpanded++;

//         if (node->state.isGoal()) {
//             std::cout << "Goal!!!" << std::endl;
//             printPath(node);
//             std::cout << "Total nodes expanded: " << nodesExpanded << std::endl;
//             std::cout << "Maximum frontier size: " << maxFrontierSize << std::endl;
//             return node;
//         }

//         if (!isInExplored(node)) {
//             explored.insert(node);
//             std::vector<Node*> successors = expand(node);
//             for (Node* successor : successors) {
//                 if (!isInExplored(successor)) {
//                     successor->heuristic = calculateEuclideanDistance(successor->state, Puzzle::getGoalState());
//                     addToFrontier(successor);
//                 }
//             }
//         }
//     }
//     std::cout << "Failure: No solution found." << std::endl;
//     return nullptr;
// }