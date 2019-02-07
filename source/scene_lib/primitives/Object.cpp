//
//  Object.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "ColoredMesh.hpp"
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
    update_matrices();
}

const Vector4& Object::rotation() const {
    return _rotation;
}

void Object::set_rotation(const Vector4& rotation) {
    _rotation = rotation;
    update_matrices();
}

void Object::stop() {
    velocity = { };
}

void Object::update() {
    _position += velocity;
    update_matrices();
}
