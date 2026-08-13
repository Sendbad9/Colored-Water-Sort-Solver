#ifndef TUBE_H
#define TUBE_H

#include <vector>

class Tube {
private:
    int capacity;
    std::vector<int> colors;

public:
    Tube(int capacity = 0);

    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    int emptySpaces() const;
    int topColor() const;
    int topColorCount() const;

    void push(int color);
    int pop();

    const std::vector<int>& getColors() const;
    void setColors(const std::vector<int>& newColors);

    int getCapacity() const;
};

#endif