//
//  BoxModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"

namespace scene {

class BoxModel : public Model {

public:

    float length;
    float width;
    float height;

    BoxModel(float size = 1);
    BoxModel(float, float, float);

};

}
