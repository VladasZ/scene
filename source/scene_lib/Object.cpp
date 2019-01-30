//
//  Object.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "ColoredMesh.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"

using namespace scene;

Object::Object(ColoredMesh* mesh) : _mesh(mesh) {

}

Object::~Object() {
    delete _mesh;
}

ColoredMesh* Object::mesh() const {
    return _mesh;
}

const Matrix4& Object::model_matrix() const {
    return _model_matrix;
}

void Object::calculate_model_matrix() {
    glm::mat4 model;
    model         = glm::translate(model,          { position.x, position.y, position.z });
    _model_matrix = glm::rotate(model, rotation.w, { rotation.x, rotation.y, rotation.z });
}

const Matrix4& Object::mvp_matrix() const {
    return _mvp_matrix;
}

void Object::calculate_mvp_matrix() {
    _scene->camera->update_view_matrix();
    _scene->camera->update_projection_matrix();
    calculate_model_matrix();
    _mvp_matrix = _scene->camera->projection_matrix() * _model_matrix * _scene->camera->view_matrix();
}
