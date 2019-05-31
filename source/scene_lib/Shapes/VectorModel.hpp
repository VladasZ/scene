//
//  VectorModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"

namespace scene {
class VectorModel : public Model {
public:
    VectorModel();

    void visualize_vector(const gm::Vector3&);
    void visualize_line_segment(const gm::LineSegment&);
};
}
