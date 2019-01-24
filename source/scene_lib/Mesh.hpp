//
//  Mesh.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <cstdint>

#include "Vector3.hpp"

namespace scene {

class Mesh {

public:

    std::vector<Vector3> vertices;
    std::vector<uint8_t> indices;

    Mesh() = default;
    Mesh(const std::vector<Vector3>&, const std::vector<uint8_t>&);

    const char* to_string() const;

};

}
