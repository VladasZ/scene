//
//  Box.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Object.hpp"

namespace scene {

class Box : public Object {

public:

    float length;
    float width;
    float height;

    Box(float = 1, float = 1, float = 1);

    void refresh_mesh();
};

}
