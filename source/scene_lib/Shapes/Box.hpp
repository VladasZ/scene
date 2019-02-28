//
//  Box.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"

namespace scene {

class Box : public Model {

public:

    float length;
    float width;
    float height;

    Box(float size = 1);
    Box(float, float, float);

};

}
