#include "Puzzle.h"

#include <iostream>
#include <sstream>

Puzzle::Puzzle(int numberOfTubes, int capacity)
    : capacity(capacity) {
    tubes.reserve(numberOfTubes);

    for (int i = 0; i < numberOfTubes; ++i) {
        tubes.emplace_back(capacity);
    }
}

Tube& Puzzle::getTube(int index) {
    return tubes[index];
}

const Tube& Puzzle::getTube(int index) const {
    return tubes[index];
}

int Puzzle::getNumberOfTubes() const {
    return static_cast<int>(tubes.size());
}

int Puzzle::getCapacity() const {
    return capacity;
}

bool Puzzle::isValidMove(int source, int destination) const {
    if (source < 0 || source >= getNumberOfTubes()) {
        return false;
    }

    if (destination < 0 || destination >= getNumberOfTubes()) {
        return false;
    }

    if (source == destination) {
        return false;
    }

    const Tube& sourceTube = tubes[source];
    const Tube& destinationTube = tubes[destination];

    if (sourceTube.isEmpty()) {
        return false;
    }

    if (destinationTube.isFull()) {
        return false;
    }

    int sourceColor = sourceTube.topColor();

    // Destination must either be empty
    // or have the same color on top.
    if (!destinationTube.isEmpty() &&
        destinationTube.topColor() != sourceColor) {
        return false;
    }

    return true;
}

void Puzzle::applyMove(int source, int destination) {
    if (!isValidMove(source, destination)) {
        return;
    }

    Tube& sourceTube = tubes[source];
    Tube& destinationTube = tubes[destination];

    int amount = sourceTube.topColorCount();

    if (amount > destinationTube.emptySpaces()) {
        amount = destinationTube.emptySpaces();
    }

    for (int i = 0; i < amount; ++i) {
        destinationTube.push(sourceTube.pop());
    }
}

std::vector<Move> Puzzle::generateValidMoves() const {
    std::vector<Move> moves;

    for (int source = 0; source < getNumberOfTubes(); ++source) {
        for (int destination = 0;
             destination < getNumberOfTubes();
             ++destination) {

            if (isValidMove(source, destination)) {
                moves.push_back({source, destination});
            }
        }
    }

    return moves;
}
bool Puzzle::isSolved() const {
    for (const Tube& tube : tubes) {
        if (tube.isEmpty()) {
            continue;
        }

        if (!tube.isFull()) {
            return false;
        }

        const std::vector<int>& colors = tube.getColors();
        int firstColor = colors[0];

        for (int color : colors) {
            if (color != firstColor) {
                return false;
            }
        }
    }

    return true;
}
std::string Puzzle::encode() const {
    std::ostringstream state;

    for (const Tube& tube : tubes) {
        const std::vector<int>& colors = tube.getColors();

        for (int color : colors) {
            state << color << ',';
        }

        state << '|';
    }

    return state.str();
}

void Puzzle::setTube(int index, const std::vector<int>& colors) {
    if (index < 0 || index >= getNumberOfTubes()) {
        return;
    }

    tubes[index].setColors(colors);
}

void Puzzle::print() const {
    for (int i = 0; i < getNumberOfTubes(); ++i) {
        std::cout << "Tube " << i + 1 << ": [";

        const std::vector<int>& colors = tubes[i].getColors();

        for (int j = 0; j < static_cast<int>(colors.size()); ++j) {
            std::cout << colors[j];

            if (j != static_cast<int>(colors.size()) - 1) {
                std::cout << ",";
            }
        }

        // Print remaining empty positions.
        for (int j = static_cast<int>(colors.size());
             j < capacity;
             ++j) {

            if (j > 0 || !colors.empty()) {
                std::cout << ",";
            }

            std::cout << "0";
        }

        std::cout << "]\n";
    }
}