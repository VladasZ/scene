//
//  Rotatable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Rotatable.hpp"

using namespace gm;
using namespace scene;

void Rotatable::look_at(const Vector3& target) {
    _rotation_matrix = Matrix4::transform::model_look_at(target);
    _need_matrices_update = true;
}

const Vector3& Rotatable::pivot() const {
    return _pivot;
}

void Rotatable::set_pivot(const Vector3& pivot) {
    _pivot = pivot;
    _need_matrices_update = true;
}

const Vector4& Rotatable::rotation() const {
    return _rotation;
}

void Rotatable::set_rotation(const Vector4& rotation) {
    _rotation = rotation;
}

const Matrix4& Rotatable::rotation_matrix() const {
    return _rotation_matrix;
}

void Rotatable::set_rotation_matrix(const Matrix4& rotation_matrix) {
    _rotation_matrix = rotation_matrix;
    _need_matrices_update = true;
}

void Rotatable::add_rotation(const Matrix4& rotation) {
    _rotation_matrix = rotation *_rotation_matrix;
    _need_matrices_update = true;
}

void Rotatable::update_matrices() {
    Translatable::update_matrices();
//    auto rotation          = glm::rotate(glm::mat4 { }, _rotation.w, { _rotation.x, _rotation.y, _rotation.z });
//    auto translate_pivot   = Matrix4::transform::translation(_pivot);
//    auto untranslate_pivot = translate_pivot.inversed();
    //_rotation_matrix =  translate_pivot * rotation * untranslate_pivot;
}
