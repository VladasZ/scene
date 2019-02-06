//
//  Object.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Vector3.hpp"
#include "Vector4.hpp"

namespace scene {

class Scene;

class Object {

    friend Scene;

protected:

    Scene* _scene;

public:

    Vector3 velocity;

    Vector3 position;
    Vector4 rotation { 1, 0, 0, 0 };

    virtual ~Object();

    void stop();

    virtual void update();
};

}
