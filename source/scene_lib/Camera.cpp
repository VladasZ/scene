//
//  Camera.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/euler_angles.hpp"

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

    Matrix4 rotation = glm::eulerAngleXZ(shift.y, shift.x);

    _position = rotation * (_position - _target) + _target;
    //_up = rotation * _up;

    update_matrices();
}

void Camera::update_matrices() {

    _view_matrix = glm::lookAt(
              { _position.x, _position.y, _position.z },
              {   _target.x,   _target.y,   _target.z },
    glm::vec3 {       _up.x,       _up.y,       _up.z }
    );

    _projection_matrix = glm::perspective(fov, resolution.width / resolution.height, z_near, z_far);

    for (auto obj : _scene->_objects) {
        if (obj != this)
            obj->update_matrices();
    }
}

void Camera::update() {
    _target += velocity;
    Movable::update();
}

