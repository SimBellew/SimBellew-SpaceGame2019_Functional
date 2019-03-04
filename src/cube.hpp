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

        Cube() {}
        Cube(components::Types cube_type, int cube_mass, vectors::vector3 cube_loc)
        {
            type = cube_type;
            mass = cube_mass;
            offset = cube_loc;
        }
    };

    Cube NodeToCube(const YAML::Node &node);
}

#endif /* CUBE_H_ */