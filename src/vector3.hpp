#ifndef VECTOR_H_
#define VECTOR_H_

#include <string>
#include <sstream>
#include <yaml-cpp/yaml.h>

namespace vectors
{
    struct vector3
    {
        int x;
        int y;
        int z;

        std::string as_string()
        {
            std::ostringstream oss;
            oss << "x: " << x << " y: " << y << " z: " << z;
            return oss.str();
        }

        vector3() { }
        vector3(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }
        vector3(YAML::Node node)
        {
            x = node["x"].as<int>();
            y = node["y"].as<int>();
            z = node["z"].as<int>();
        }
    };
}

#endif /* VECTOR_H_ */