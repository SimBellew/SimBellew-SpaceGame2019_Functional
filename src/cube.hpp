#ifndef CUBE_H_
#define CUBE_H_

#include <yaml-cpp/yaml.h>
#include "component.hpp"
#include "vector3.hpp"

namespace cubes
{
    struct Cube
    {
        components::Types type;
        int mass;
        vectors::vector3 offset;
        double allocated_energy;
        Cube *next;

        Cube() {}
        Cube(components::Types cube_type, int cube_mass, vectors::vector3 cube_loc, Cube * cube_next)
        {
            type = cube_type;
            mass = cube_mass;
            offset = cube_loc;
            next = cube_next;
        }
        Cube(YAML::Node cube, Cube *next_cube)
        {
            type = static_cast<components::Types>(cube["type"].as<int>());
            mass = cube["mass"].as<int>();
            offset = vectors::vector3(cube["offset"]);
            next = next_cube;
        }
    };

    Cube *LoadCube(YAML::Node node, u_int index);
}

#endif /* CUBE_H_ */