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

#include "Scene.hpp"
#include "Camera.hpp"

using namespace scene;

const Matrix4& Camera::view_matrix() const {
    return _view_matrix;
}

const Matrix4& Camera::projection_matrix() const {
    return _projection_matrix;
}

void Camera::update_matrices() {
    _view_matrix = glm::lookAt(
    { _position.x, _position.y, _position.z }, // Camera is at (4,3,3), in World Space
    { 0,0,0 }, // and looks at the origin
                glm::vec3(0,0,1)  // Head is up (set to 0,-1,0 to look upside-down)
                );

    _projection_matrix = glm::perspective(fov, resolution.width / resolution.height, z_near, z_far);

    for (auto obj : _scene->_objects) {
        if (obj != this)
            obj->update_matrices();
    }
}

