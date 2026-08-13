#ifndef SOLVER_H
#define SOLVER_H

#include "Puzzle.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct ParentInfo {
    std::string parentState;
    Move move;
};

class Solver {
private:
    std::vector<Move> reconstructPath(
        const std::string& startState,
        const std::string& goalState,
        const std::unordered_map<std::string, ParentInfo>& parent
    ) const;

public:
    std::vector<Move> solve(const Puzzle& initialPuzzle);
};

#endif