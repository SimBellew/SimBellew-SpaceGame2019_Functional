#ifndef SHIP_H_
#define SHIP_H_

#include <yaml-cpp/yaml.h>
#include "cube.hpp"
#include "vector3.hpp"
#include <algorithm>
#include <iterator>

namespace ships
{
    struct ShipStats
    {
        vectors::vector3 velocity;
        double AP;
        double EP;
        vectors::vector3 facing;
    };

    struct Ship
    {
        std::string name;
        cubes::Cube *cube;
        vectors::vector3 *location;
        ShipStats *stats;
        Ship *next;

        Ship() { }
        Ship(std::string ship_name, cubes::Cube *ship_cubes, vectors::vector3 *ship_loc, Ship *ship_next)
        {
            name = ship_name;
            cube = ship_cubes;
            location = ship_loc;
            stats = new ShipStats();
            next = ship_next;
        }
        Ship(Ship *ship, std::string action)
        {

        }
        Ship(const Ship &ship, std::string action)
        {
            
        }
    };

    static const std::string ActionStrings[] = { "Accelerate", "Rotate", "Fire", "Back"};

    Ship *LoadShip(YAML::Node ship_yaml, Ship *next);

    Ship *DeriveTurnStats(const Ship &ship);

    bool TestShipAction(const Ship &ship, std::string action);
}

#endif /* SHIP_H_ */