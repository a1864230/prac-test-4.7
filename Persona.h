#ifndef PERSONA_H
#define PERSONA_H

#include "Spot.h"

class Persona : public Spot {
public:
// Constructor
Persona(int x, int y) : Spot(x, y, 'P') {}

// Member function to shift the Persona's location
void shift(int dx, int dy) {
int x, y;
std::tie(x, y) = getLoc();
x += dx;
y += dy;
setLoc(x, y);
}
};

#endif // PERSONA_H