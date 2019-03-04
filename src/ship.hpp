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
        std::vector<cubes::Cube> cubes;
        vectors::vector3 *location;
        ShipStats *stats;
        Ship *next;

        Ship() { }
        Ship(std::string ship_name, std::vector<cubes::Cube> ship_cubes, vectors::vector3 *ship_loc)
        {
            name = ship_name;
            cubes = ship_cubes;
            location = ship_loc;
            stats = new ShipStats();
            next = NULL;
        }
    };

    enum Actions
    {
        Accelerate = 0,
        Rotate = 0,
        Fire = 0,

    };

    Ship *LoadShip(std::string filename, Ship *next);

    Ship *DeriveTurnStats(Ship *ship);

    bool TestAction(Ship *ship, Actions action);
}

#endif /* SHIP_H_ */