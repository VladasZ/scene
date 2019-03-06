//
//  TexturedVertex.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vertex.hpp"

namespace scene {

class TexturedVertex : public Vertex {

public:

    using Array = std::vector<TexturedVertex>;

    gm::Point texture_coordinate;

    TexturedVertex() = default;
    TexturedVertex(const gm::Vector3& position, const gm::Vector3& normal, const gm::Point& texture_coordinate);

};

}
