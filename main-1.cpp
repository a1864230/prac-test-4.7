#include "Spot.h"
#include "Influence.h"
#include "Assists.h"
#include <iostream>

class MyInfluence : public Influence {
public:
    void applyInfluence(Spot& spot) override {
        // Implement your own logic for applying influence
        std::cout << "Applying influence to spot at location " << std::get<0>(spot.getLoc()) << ", " << std::get<1>(spot.getLoc()) << " with category " << spot.getCategory() << std::endl;
    }
};

int main() {
    Spot spot1(1, 2, 'A');
    Spot spot2 = Assists::createRandomLoc(10);

    std::cout << "Spot 1 location: " << std::get<0>(spot1.getLoc()) << ", " << std::get<1>(spot1.getLoc()) << " with category " << spot1.getCategory() << std::endl;
    std::cout << "Spot 2 location: " << std::get<0>(spot2.getLoc()) << ", " << std::get<1>(spot2.getLoc()) << " with category " << spot2.getCategory() << std::endl;

    double distance = Assists::calculateEuclideanDistance(spot1, spot2);
    std::cout << "Euclidean distance between spot 1 and spot 2: " << distance << std::endl;

    MyInfluence influence;
    influence.applyInfluence(spot1);

    return 0;
}