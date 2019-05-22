//
//  Model.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Scene.hpp"
#include "Model.hpp"
#include "Camera.hpp"
#include "Mesh.hpp"
#include "SceneConfig.hpp"

using namespace gm;
using namespace scene;

Model::Drawer::~Drawer() {

}

Model::Model(Mesh* mesh, Image* image) : _draw_mode(DrawMode::Triangles), _mesh(mesh), _image(image) {
    _drawer = config::drawer->init_model_drawer(this);
}

Model::Model(Mesh* mesh, DrawMode draw_mode) : _draw_mode(draw_mode), _mesh(mesh), _image(nullptr) {
    _drawer = config::drawer->init_model_drawer(this);
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

void Model::draw_normals() {
    if (_need_matrices_update)
        update_matrices();

    for (auto ver : mesh()->vertices()) {
        _scene->_dummy_vector->set_position(_model_matrix * ver.position);
        _scene->_dummy_vector->look_at(_model_matrix.multiply_by_normal(ver.normal));
        _scene->_dummy_vector->draw();
    }
}

bool Model::has_image() const {
    return _image;
}

Image* Model::image() const {
    return _image;
}

const Matrix4& Model::model_matrix() const {
    return _model_matrix;
}

const Matrix4& Model::mvp_matrix() const {
    return _mvp_matrix;
}

void Model::update_matrices() {
    Scalable::update_matrices();
    _model_matrix = _translation_matrix * _rotation_matrix * _scale_matrix;
    _mvp_matrix = _scene->camera->view_projection_matrix() * _model_matrix;
}
