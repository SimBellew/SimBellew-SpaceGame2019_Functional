#include "ship.hpp"


ships::Ship *ships::LoadShip(YAML::Node ship_yaml, ships::Ship *next)
{
    // Parse location
    vectors::vector3 *location = new vectors::vector3(ship_yaml["location"]);
    cubes::Cube *cube = cubes::LoadCube(ship_yaml["cubes"], 0);
    //cubes::Cube *cube = new cubes::Cube(ship_yaml["cubes"][0], NULL);

    // Return ship
    return new ships::Ship(ship_yaml["name"].as<std::string>(), cube, location, NULL);
    
    //std::string lol = ship_yaml["name"].as<std::string>();

    //return new ships::Ship();
}

bool ships::TestShipAction(const ships::Ship &ship, std::string action)
{
    return true;
}

ships::Ship *ships::DeriveTurnStats(ships::Ship *ship)
{
    return ship;
}