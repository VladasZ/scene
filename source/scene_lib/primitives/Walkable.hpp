//
//  Walkable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Movable.hpp"

namespace scene {

class Walkable : public Movable {

public:

    enum Direction {
        Forward = 0b0001,
        Back    = 0b0010,
        Left    = 0b0100,
        Right   = 0b1000
    };

private:

    virtual const Vector3& _direction() = 0;

public:

    float walking_speed = 0.1f;

    void walk(Direction);


};

}
