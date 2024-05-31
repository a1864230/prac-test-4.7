#include "Play.h"
#include <iostream>

int main() {
Play play;
play.initPlay(5, 3, 10, 10);
play.playCycle(100, 1.5);

return 0;
}