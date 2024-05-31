#ifndef ASSISTS_H
#define ASSISTS_H

#include "Spot.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

class Assists {
public:
    // Static method to create a random location in the grid
    static Spot createRandomLoc(int gridSize) {
        srand(time(0));
        int x = rand() % gridSize;
        int y = rand() % gridSize;
        char c = 'A' + (rand() % 26); // Random category from A to Z
        return Spot(x, y, c);
    }

    // Static method to evaluate the Euclidean distance between two locations
    static double calculateEuclideanDistance(const Spot& spot1, const Spot& spot2) {
        int x1, y1;
        std::tie(x1, y1) = spot1.getLoc();
        int x2, y2;
        std::tie(x2, y2) = spot2.getLoc();
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    }
};

#endif // ASSISTS_H