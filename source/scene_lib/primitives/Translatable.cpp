//
//  Movable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Translatable.hpp"

using namespace scene;


const Matrix4& Translatable::translation_matrix() const {
    return _translation_matrix;
}

void Translatable::update_matrices() {
    _translation_matrix = glm::translate(glm::mat4 { }, { _position.x, _position.y, _position.z });
}
