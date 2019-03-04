#include "cube.hpp"

// TODO convert yaml node to cube
cubes::Cube cubes::NodeToCube(const YAML::Node &node)
{
    components::Types type = static_cast<components::Types>( node["type"].as<int>());

    return cubes::Cube(type, node["mass"].as<int>(), vectors::vector3(node["location"]));
}