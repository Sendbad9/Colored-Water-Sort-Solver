#include "Solver.h"

#include <queue>
#include <algorithm>

std::vector<Move> Solver::reconstructPath(
    const std::string& startState,
    const std::string& goalState,
    const std::unordered_map<std::string, ParentInfo>& parent
) const {
    std::vector<Move> path;

    std::string currentState = goalState;

    while (currentState != startState) {
        auto it = parent.find(currentState);

        if (it == parent.end()) {
            return {};
        }

        path.push_back(it->second.move);
        currentState = it->second.parentState;
    }

    std::reverse(path.begin(), path.end());

    return path;
}

std::vector<Move> Solver::solve(const Puzzle& initialPuzzle) {
    std::queue<Puzzle> bfsQueue;

    std::unordered_set<std::string> visited;

    std::unordered_map<std::string, ParentInfo> parent;

    std::string startState = initialPuzzle.encode();

    bfsQueue.push(initialPuzzle);
    visited.insert(startState);

    while (!bfsQueue.empty()) {
        Puzzle currentPuzzle = bfsQueue.front();
        bfsQueue.pop();

        std::string currentState = currentPuzzle.encode();

        if (currentPuzzle.isSolved()) {
            return reconstructPath(
                startState,
                currentState,
                parent
            );
        }

        std::vector<Move> moves = currentPuzzle.generateValidMoves();

        for (const Move& move : moves) {
            Puzzle nextPuzzle = currentPuzzle;

            nextPuzzle.applyMove(
                move.source,
                move.destination
            );

            std::string nextState = nextPuzzle.encode();

            if (visited.find(nextState) != visited.end()) {
                continue;
            }

            visited.insert(nextState);

            parent[nextState] = {
                currentState,
                move
            };

            bfsQueue.push(nextPuzzle);
        }
    }

    return {};
}