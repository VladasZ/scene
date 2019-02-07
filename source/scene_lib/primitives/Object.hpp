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

    Vector3 _position;
    Vector4 _rotation { 1, 0, 0, 0 };

public:

    Vector3 velocity;

    virtual ~Object();

    const Vector3& position() const;
    void set_position(const Vector3&);

    const Vector4& rotation() const;
    void set_rotation(const Vector4&);

    void stop();

    virtual void update_matrices() = 0;
    virtual void update();
};

}
