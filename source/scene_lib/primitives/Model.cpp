//
//  Model.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Scene.hpp"
#include "Model.hpp"
#include "Camera.hpp"
#include "ColoredMesh.hpp"

using namespace scene;

Model::Model(ColoredMesh* mesh) : _mesh(mesh) {

}

Model::~Model() {
    delete _mesh;
}

ColoredMesh* Model::mesh() const {
    return _mesh;
}

const Matrix4& Model::model_matrix() const {
    return _model_matrix;
}

void Model::calculate_model_matrix() {
    glm::mat4 model;
    model         = glm::translate(model,          { position.x, position.y, position.z });
    _model_matrix = glm::rotate(model, rotation.w, { rotation.x, rotation.y, rotation.z });
}

const Matrix4& Model::mvp_matrix() const {
    return _mvp_matrix;
}

void Model::calculate_mvp_matrix() {
    _scene->camera->update_view_matrix();
    _scene->camera->update_projection_matrix();
    calculate_model_matrix();
    _mvp_matrix = _scene->camera->projection_matrix() * _scene->camera->view_matrix() * _model_matrix;

}
