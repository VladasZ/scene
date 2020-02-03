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

using namespace gm;
using namespace scene;

Object::Object() : position({ _position }) {
    position.did_set = [&] { _need_matrices_update = true; };
}

Object::Object(const Vector3& position) : Object() {
    _position = position;
}

Object::~Object() {

}

void Object::update_matrices() {

}

void Object::update() {

}
