#include "cube.hpp"

cubes::Cube *cubes::LoadCube(YAML::Node node, u_int index)
{
    if (index >= node.size()) return NULL;

    return new cubes::Cube(node[index], cubes::LoadCube(node, index + 1));
}