#include "Tube.h"

Tube::Tube(int capacity) : capacity(capacity) {}

bool Tube::isEmpty() const {
    return colors.empty();
}

bool Tube::isFull() const {
    return static_cast<int>(colors.size()) == capacity;
}

int Tube::size() const {
    return static_cast<int>(colors.size());
}

int Tube::emptySpaces() const {
    return capacity - size();
}

int Tube::topColor() const {
    if (colors.empty()) {
        return 0;
    }

    return colors.back();
}

int Tube::topColorCount() const {
    if (colors.empty()) {
        return 0;
    }

    int color = colors.back();
    int count = 0;

    for (int i = static_cast<int>(colors.size()) - 1; i >= 0; --i) {
        if (colors[i] == color) {
            count++;
        } else {
            break;
        }
    }

    return count;
}

void Tube::push(int color) {
    if (!isFull()) {
        colors.push_back(color);
    }
}

int Tube::pop() {
    if (isEmpty()) {
        return 0;
    }

    int color = colors.back();
    colors.pop_back();

    return color;
}

const std::vector<int>& Tube::getColors() const {
    return colors;
}

void Tube::setColors(const std::vector<int>& newColors) {
    colors = newColors;
}

int Tube::getCapacity() const {
    return capacity;
}