#include "game.hpp"

int main() {
    std::cout << "SpaceGame2019 Simulator" << std::endl;
    
    // Start from a test point
    StepGame(LoadState("test"));
}