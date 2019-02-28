//
//  Vertex.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"

namespace scene {

class Vertex {

public:

    using Index = unsigned short;
    using Array = std::vector<Vertex>;

    Vector3 position;
    Vector3 normal;

    Vertex() = default;
    Vertex(const Vector3& position, const Vector3& normal);

    std::string to_string() const;
};

}
