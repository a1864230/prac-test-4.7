#include "Snare.h"
#include "Persona.h"
#include <iostream>

int main() {
Snare trap(1, 2);
Persona character(3, 4);

std::cout << "Trap location: " << std::get<0>(trap.getLoc()) << ", " << std::get<1>(tra) << " with category " << trap.getCategory() << std::endl;
std::cout << "Character location: " << std::get<0>(characte) << ", " << std::get<1>(characte) << " with category " << character.getCategory() << std::endl;

trap.applyInfluence(character);

std::cout << "Character location after trap influence: " << std::get<0>(characte) << ", " << std::get<1>(characte) << " with category " << character.getCategory() << std::endl;

return 0;
}