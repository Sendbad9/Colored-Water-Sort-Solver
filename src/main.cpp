#include "Puzzle.h"
#include "Solver.h"

#include <iostream>
#include <vector>

int main() {
    int numberOfTubes;
    int capacity;

    std::cin >> numberOfTubes;
    std::cin >> capacity;

    Puzzle puzzle(numberOfTubes, capacity);

    for (int i = 0; i < numberOfTubes; ++i) {
        std::vector<int> colors;

        for (int j = 0; j < capacity; ++j) {
            int color;
            std::cin >> color;

            if (color != 0) {
                colors.push_back(color);
            }
        }

        puzzle.setTube(i, colors);
    }

    Solver solver;

    std::vector<Move> solution = solver.solve(puzzle);

    if (!puzzle.isSolved() && solution.empty()) {
        std::cout << "No solution exists.\n";
        return 0;
    }

    std::cout << "Solution found.\n";
    std::cout << "Minimum moves: "
              << solution.size()
              << "\n";

    for (size_t i = 0; i < solution.size(); ++i) {
        std::cout << i + 1
                  << ". Tube "
                  << solution[i].source + 1
                  << " -> Tube "
                  << solution[i].destination + 1
                  << "\n";
    }

    Puzzle finalPuzzle = puzzle;

    for (const Move& move : solution) {
        finalPuzzle.applyMove(
            move.source,
            move.destination
        );
    }

    std::cout << "Final state:\n";
    finalPuzzle.print();

    return 0;
}