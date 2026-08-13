#ifndef PUZZLE_H
#define PUZZLE_H

#include "Tube.h"
#include <string>
#include <vector>

struct Move {
    int source;
    int destination;
};

class Puzzle {
private:
    int capacity;
    std::vector<Tube> tubes;

public:
    Puzzle(int numberOfTubes = 0, int capacity = 0);

    Tube& getTube(int index);
    const Tube& getTube(int index) const;

    int getNumberOfTubes() const;
    int getCapacity() const;

    bool isValidMove(int source, int destination) const;
    void applyMove(int source, int destination);

    std::vector<Move> generateValidMoves() const;

    bool isSolved() const;

    std::string encode() const;

    void setTube(int index, const std::vector<int>& colors);

    void print() const;
};

#endif