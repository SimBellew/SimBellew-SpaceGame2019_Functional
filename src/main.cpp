#include "game.hpp"
#include <yaml-cpp/yaml.h>
#include <iostream>

YAML::Node LoadYaml()
{
    YAML::Node ship_yaml = YAML::LoadFile("lol.yaml");
    return ship_yaml;
}

int main() {
    std::cout << "SpaceGame2019 Simulator" << std::endl;

    // Start from a test point
    StepGame(LoadState(LoadYaml()));
}