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
#include "Mesh.hpp"

using namespace scene;

Model::Model(Mesh* mesh) : _mesh(mesh) {

}

Model::~Model() {
    delete _mesh;
}

Mesh* Model::mesh() const {
    return _mesh;
}

const Matrix4& Model::mvp_matrix() const {
    return _mvp_matrix;
}

void Model::update_matrices() {
    Rotatable::update_matrices();
    _mvp_matrix = _scene->camera->projection_matrix() * _scene->camera->view_matrix() * _translation_matrix * _rotation_matrix;
}
