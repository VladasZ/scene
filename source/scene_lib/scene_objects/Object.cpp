//
//  Object.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"

using namespace scene;

Object::~Object() {

}

const Vector3& Object::position() const {
    return _position;
}

void Object::set_position(const Vector3& position) {
    _position = position;
    _need_matrices_update = true;
}

