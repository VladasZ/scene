//
//  Mesh.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <cstdint>

#include "Vector3.hpp"

namespace scene {

class Mesh {

public:

    const std::vector<Vector3> vertices;
    const std::vector<unsigned short> indices;
    const Vector3 middle_point;

    Mesh() = default;
    Mesh(const std::vector<Vector3>&);
    Mesh(const std::vector<Vector3>&, const std::vector<unsigned short>&);
    virtual ~Mesh();

    const char* to_string() const;

};

}
