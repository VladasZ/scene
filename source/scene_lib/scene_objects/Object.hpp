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

public:

    Scene* _scene = nullptr;

    gm::Vector3 _position;

public:

    Object()              = default;
    Object(const gm::Vector3& position);
    virtual               ~Object();

    const gm::Vector3& position()         const;
    void       set_position(const gm::Vector3&);

    virtual void update_matrices();
    virtual void update         ();
};

}
