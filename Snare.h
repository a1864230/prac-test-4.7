#ifndef SNARE_H
#define SNARE_H

#include "Spot.h"
#include "Influence.h"

class Snare : public Spot, public Influence {
private:
bool operative;

public:
// Constructor
Snare(int x, int y) : Spot(x, y, 'S'), operative(true) {}

// Member function to check if the snare is active
bool isOperative() const {
return operative;
}

// Member function to deactivate the snare
void deactivate() {
operative = false;
}

// Implementation of the pure virtual function from Influence
void applyInfluence(Spot& spot) override {
if (isOperative()) {
spot.setCategory('S');
deactivate();
}
}

// Additional member function to implement the influence
void implement(Spot& spot) {
applyInfluence(spot);
}
};

#endif // SNARE_H