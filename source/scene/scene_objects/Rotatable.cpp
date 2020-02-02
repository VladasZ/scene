//
//  Rotatable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Rotatable.hpp"

using namespace gm;
using namespace scene;

void Rotatable::look_at(const Vector3& target) {
    _rotation_matrix = Matrix4::transform::model_look_at(target);
    _need_matrices_update = true;
}

const Vector4& Rotatable::rotation() const {
    return _rotation;
}

void Rotatable::set_rotation(const Vector4& rotation) {
    _rotation = rotation;
    _need_matrices_update = true;
}

const Matrix4& Rotatable::rotation_matrix() const {
    return _rotation_matrix;
}

void Rotatable::set_rotation_matrix(const Matrix4& rotation_matrix) {
    _rotation_matrix = rotation_matrix;
    _need_matrices_update = true;
}

void Rotatable::update_matrices() {
    Translatable::update_matrices();
    _rotation_matrix = Matrix4::transform::quaternion_rotation(_rotation);
}
