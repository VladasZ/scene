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

    bool _need_matrices_update = true;

    Scene* _scene = nullptr;

    Vector3 _position;

public:

    virtual ~Object();

    const Vector3& position() const;
    void set_position(const Vector3&);

    virtual void update_matrices() = 0;
    virtual void update() = 0;
};

}
