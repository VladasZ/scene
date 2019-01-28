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

#include "Camera.hpp"

using namespace scene;

const Matrix4& Camera::view_matrix() const {
    return _view_matrix;
}

const Matrix4& Camera::projection_matrix() const {
    return _projection_matrix;
}

void Camera::update_view_matrix() {
    glm::mat4 view;
    glm::translate(view, { position.x, position.y, position.z });
    _view_matrix = view;
}

void Camera::update_projection_matrix() {
    _projection_matrix = glm::perspective(fov, resolution.width / resolution.height, z_near, z_far);
}
