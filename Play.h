#ifndef PLAY_H
#define PLAY_H

#include "Spot.h"
#include "Persona.h"
#include "Snare.h"
#include <vector>

class Play {
private:
std::vector<std::vector<Spot*>> matrix;

public:
// Default constructor
Play() {}

// Function to return the matrix
const std::vector<std::vector<Spot*>>& getMatrix() const {
return matrix;
}

// Function to initialize the gameplay
void initPlay(int numPersonas, int numSnares, int matrixWidth, int matrixHeight) {
matrix.resize(matrixHeight, std::vector<Spot*>(matrixWidth, nullptr));
for (int i = 0; i < numPersonas; ++i) {
int x, y;
do {
x = rand() % matrixWidth;
y = rand() % matrixHeight;
} while (matrix[y][x]!= nullptr);
matrix[y][x] = new Persona(x, y);
}
for (int i = 0; i < numSnares; ++i) {
int x, y;
do {
x = rand() % matrixWidth;
y = rand() % matrixHeight;
} while (matrix[y][x]!= nullptr);
matrix[y][x] = new Snare(x, y);
}
}

// Function to run the game for a specified number of cycles
void playCycle(int maxCycles, double snareTriggerDistance) {
for (int cycle = 0; cycle < maxCycles; ++cycle) {
for (int y = 0; y < matrix.size(); ++y) {
for (int x = 0; x < matrix[y].size(); ++x) {
if (matrix[y][x]!= nullptr && dynamic_cast<Persona*>(matrix[y][x])!= nullptr) {
Persona* persona = dynamic_cast<Persona*>(matrix[y][x]);
persona->shift(rand() % 3 - 1, rand() % 3 - 1);
int newX, newY;
std::tie(newX, newY) = persona->getLocation();
if (newX < 0 || newX >= matrix[0].size() || newY < 0 || newY >= matrix.size()) {
std::cout << "Persona exited the matrix at cycle " << cycle << std::endl;
return;
}
for (int dy = -1; dy <= 1; ++dy) {
for (int dx = -1; dx <= 1; ++dx) {
int sx = x + dx, sy = y + dy;
if (sx >= 0 && sx < matrix[0].size() && sy >= 0 && sy < matrix.size() && matrix[sy][sx]!= nullptr && dynamic_cast<Snare*>(matrix[sy][sx])!= nullptr) {
Snare* snare = dynamic_cast<Snare*>(matrix[sy][sx]);
if (snare->isOperative() && sqrt(pow(dx, 2) + pow(dy, 2)) <= snareTriggerDistance) {
snare->applyInfluence(*persona);
}
}
}
}
}
}
}
std::cout << "Game ended after " << maxCycles << " cycles" << std::endl;
}
};

#endif // PLAY_H