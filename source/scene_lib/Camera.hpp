//
//  Camera.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Vector3.hpp"

namespace scene {

class Camera {

public:

    Vector3 position;
    Vector3 direction { 1, 0, 0 };
    float fov = 1;

};

}
