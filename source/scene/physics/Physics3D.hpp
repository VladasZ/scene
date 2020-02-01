//
//  Physics3D.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 01/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"

namespace scene {

    class Physics3D {

    public:

        static inline gm::Vector3 ground_position;
        static inline gm::Vector3 box_position;

        static void init();
        static void update();

    };

}
