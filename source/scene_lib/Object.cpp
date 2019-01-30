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

#include "Mesh.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"

using namespace scene;

Object::Object(Mesh* mesh) : _mesh(mesh) {

}

Object::~Object() {
    delete _mesh;
}

Mesh* Object::mesh() const {
    return _mesh;
}

const Matrix4& Object::model_matrix() const {
    return _model_matrix;
}

void Object::calculate_model_matrix() {
    static const glm::mat4 model;
    _model_matrix = glm::translate(model, { position.x, position.y, position.z });
}

const Matrix4& Object::mvp_matrix() const {
    return _mvp_matrix;
}

void Object::calculate_mvp_matrix() {
    _scene->camera->update_view_matrix();
    _scene->camera->update_projection_matrix();
    calculate_model_matrix();
    _mvp_matrix = _scene->camera->projection_matrix() * _scene->camera->view_matrix() * _model_matrix;
}
