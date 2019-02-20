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

using namespace scene;

void Rotatable::look_at(const Vector3& target) {

    const auto rotation_x     = std::atan2(target.y, -target.z);
    const auto cos_rotation_x = std::cos(rotation_x);

    const auto rotation_y = target.z <= 0 ?
                           -std::atan2(target.x * cos_rotation_x, -target.z) :
                            std::atan2(target.x * cos_rotation_x,  target.z);

    const auto rotation_z = std::atan2(cos_rotation_x, std::sin(rotation_x) * std::sin(rotation_y));

    _rotation_matrix = glm::eulerAngleXYZ(rotation_x, rotation_y, rotation_z);

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
//    auto rotation          = glm::rotate(glm::mat4 { }, _rotation.w, { _rotation.x, _rotation.y, _rotation.z });
//    auto translate_pivot   = Matrix4::transform::translation(_pivot);
//    auto untranslate_pivot = translate_pivot.inversed();
    //_rotation_matrix =  translate_pivot * rotation * untranslate_pivot;
}
