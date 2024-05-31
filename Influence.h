#ifndef INFLUENCE_H
#define INFLUENCE_H

#include "Spot.h"

class Influence {
public:
    // Pure virtual function
    virtual void applyInfluence(Spot& spot) = 0;
};

#endif // INFLUENCE_H