#ifndef SPOT_H
#define SPOT_H

#include <tuple>
#include <iostream>

class Spot {
private:
    std::tuple<int, int> location;
    char category;

public:
    // Constructor
    Spot(int x, int y, char c) : location(x, y), category(c) {}

    // Getters
    std::tuple<int, int> getLoc() const {
        return location;
    }

    char getCategory() const {
        return category;
    }

    // Setters
    void setLoc(int x, int y) {
        location = std::make_tuple(x, y);
    }

    void setCategory(char c) {
        category = c;
    }
};

#endif // SPOT_H