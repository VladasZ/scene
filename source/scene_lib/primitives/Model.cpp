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
#include "SceneConfig.hpp"

using namespace scene;

Model::Drawer::~Drawer() {

}

Model::Model(Mesh* mesh, DrawMode draw_mode) : _draw_mode(draw_mode), _mesh(mesh) {
    _drawer = config::drawer->init_model_drawer(this);
    _pivot = Vector3::middle_point(mesh->vertices);
}

Model::~Model() {
    delete _mesh;
}

Mesh* Model::mesh() const {
    return _mesh;
}

Model::DrawMode Model::draw_mode() const {
    return _draw_mode;
}

void Model::draw() {
    if (_need_matrices_update)
        update_matrices();
    _drawer->_draw();
}

const Matrix4& Model::view_matrix() const {
    return _view_matrix;
}

const Matrix4& Model::mvp_matrix() const {
    return _mvp_matrix;
}

void Model::update_matrices() {
    Scalable::update_matrices();
    _view_matrix = _translation_matrix * _rotation_matrix * _scale_matrix;
    _mvp_matrix = _scene->camera->view_projection_matrix() * _view_matrix;
}
