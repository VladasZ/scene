//
//  Camera.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "Scene.hpp"
#include "Camera.hpp"

using namespace scene;

const Matrix4& Camera::view_matrix() const {
    return _view_matrix;
}

const Matrix4& Camera::projection_matrix() const {
    return _projection_matrix;
}

void Camera::move_orbit(const Point& shift) {

    auto rotation_z = Matrix4::transform::rotation_z(shift.x);
    auto rotation_x = Matrix4::transform::rotation_x(shift.y);

    Matrix4 rotation = rotation_x * rotation_z;

    _position = rotation * (_position - _target) + _target;

    update_matrices();
}

void Camera::update_matrices() {

    _view_matrix = Matrix4::transform::look_at(_position, _target, _up);

    _projection_matrix =  Matrix4::transform::perspective(fov, resolution.width / resolution.height, z_near, z_far);

    for (auto obj : _scene->_objects) {
        if (obj != this)
            obj->update_matrices();
    }
}

void Camera::update() {
    _target += velocity;
    Movable::update();
}

const Vector3& Camera::_direction() {
    static Vector3 direction;
    direction = _target - _position;
    return direction;
}

