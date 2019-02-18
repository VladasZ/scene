//
//  Rotatable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Rotatable.hpp"

using namespace scene;

void Rotatable::look_at(const Vector3& target) {
    static const Vector3 up = { 0, 0, 1 };
    //const Vector3 eye = _pivot - _position;
    //_rotation = Vector4::look_at_quaternion({ }, target, up);
    _rotation_matrix = Matrix4::transform::look_at({ }, target, up);
    update_matrices();
}

const Vector3& Rotatable::pivot() const {
    return _pivot;
}

void Rotatable::set_pivot(const Vector3& pivot) {
    _pivot = pivot;
    update_matrices();
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

void Rotatable::update_matrices() {
    Translatable::update_matrices();

    auto rotation          = glm::rotate(glm::mat4 { }, _rotation.w, { _rotation.x, _rotation.y, _rotation.z });
    auto translate_pivot   = Matrix4::transform::translation(_pivot);
    auto untranslate_pivot = translate_pivot.inversed();

    //_rotation_matrix =  translate_pivot * rotation * untranslate_pivot;
}
