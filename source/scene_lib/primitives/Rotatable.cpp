//
//  Rotatable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Rotatable.hpp"

using namespace scene;

const Vector4& Rotatable::rotation() const {
    return _rotation;
}

void Rotatable::set_rotation(const Vector4& rotation) {
    _rotation = rotation;
}

const Matrix4& Rotatable::rotation_matrix() const {
    return _rotation_matrix;
}

void Rotatable::update_matrices() {
    Translatable::update_matrices();
    _rotation_matrix = glm::rotate(glm::mat4 { }, _rotation.w, { _rotation.x, _rotation.y, _rotation.z });
}
