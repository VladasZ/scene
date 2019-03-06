//
//  ColoredVertex.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include "Vertex.hpp"

namespace scene {

class ColoredVertex : public Vertex {

public:

    using Array = std::vector<ColoredVertex>;

    gm::Color color;

    ColoredVertex() = default;
    ColoredVertex(const gm::Vector3& position, const gm::Vector3& normal);
    ColoredVertex(const gm::Vector3& position, const gm::Vector3& normal, const gm::Color& color);

};

}
