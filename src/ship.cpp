#include "ship.hpp"

ships::Ship *ships::LoadShip(std::string filename, ships::Ship *next)
{
    // Parse ship file
    YAML::Node ship_yaml = YAML::LoadFile(filename);

    // Parse ship cubes
    std::vector<YAML::Node> source_nodes = ship_yaml["cubes"].as<std::vector<YAML::Node>>();
    std::vector<cubes::Cube> ship_cubes;
    std::back_insert_iterator< std::vector<cubes::Cube> > back_it (ship_cubes);
    std::transform(source_nodes.begin(), source_nodes.end(), back_it, cubes::NodeToCube);

    // Parse location
    vectors::vector3 *location = new vectors::vector3(ship_yaml["location"]);
    
    // Return ship
    return new ships::Ship(ship_yaml["name"].as<std::string>(), ship_cubes, location);
}

bool ships::TestAction(ships::Ship *ship, ships::Actions action)
{
    return true;
}

ships::Ship *ships::DeriveTurnStats(ships::Ship *ship)
{
    return ship;
}