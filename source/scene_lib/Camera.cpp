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

using namespace gm;
using namespace scene;

Camera::Camera() {
    set_position(_target + 10.0f);
}

const Matrix4& Camera::view_matrix() const {
    return _view_matrix;
}

const Matrix4& Camera::projection_matrix() const {
    return _projection_matrix;
}

const Matrix4& Camera::view_projection_matrix() const {
    return _view_projection_matrix;
}

void Camera::set_target(const Vector3& target) {
    _target = target;
    update_matrices();
}

const Vector3& Camera::target() const {
    return _target;
}

void Camera::move_orbit(const Point& shift) {
    auto relative_position = _position - _target;
    relative_position.orbit_shift(shift);
    _position = relative_position + _target;
    update_matrices();
}

const Vector3& Camera::direction() {
    static Vector3 direction;
    direction = _target - _position;
    return direction;
}

Ray Camera::cast_ray(const gm::Point& location) {

    Vector4 start = {
        (location.x / resolution.width - 0.5f) * 2.0f,
        ((resolution.height - location.y) / resolution.height - 0.5f) * 2.0f,
        -1,
    };

    Vector4 end = {
        (location.x / resolution.width - 0.5f) * 2.0f,
        ((resolution.height - location.y) / resolution.height - 0.5f) * 2.0f,
        0,
    };

    const auto inversed_transform = view_projection_matrix().inversed();

    start = inversed_transform * start; start /= start.w;
    end   = inversed_transform *   end;   end /=   end.w;

    Ray ray { start, end };

    ray.dir = (ray.direction_vector() * 100) + ray.orig;

    return { ray.dir, ray.orig };
}

void Camera::update_matrices() {

    _view_matrix            = Matrix4::transform::look_at(_position, _target, _up);
    _projection_matrix      = Matrix4::transform::perspective(fov, resolution.width / resolution.height, z_near, z_far);
    _view_projection_matrix = _projection_matrix * _view_matrix;

    for (auto obj : _scene->_objects) {
        if (obj != this)
            obj->update_matrices();
    }
}

void Camera::update() {
    _target += velocity;
    Movable::update();
}
