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

    gm::Vector3 _position;

public:

    Scene* _scene = nullptr;

public:

    Object();
    Object(const gm::Vector3& position);
    virtual ~Object();

    virtual void update_matrices();
    virtual void update();

public:

    gm::Vector3 position() const;
    gm::Vector3& edit_position();

};

}
