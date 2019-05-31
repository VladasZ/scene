//
//  Scene.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Grid.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "BoxModel.hpp"
#include "ArrayUtils.hpp"
#include "PointLight.hpp"
#include "VectorModel.hpp"

using namespace gm;
using namespace scene;


Scene::Scene() : camera(new Camera()) {
    add_object(camera);

    _dummy_box = new BoxModel();
    _dummy_vector = new VectorModel();

    _dummy_box->is_hidden = true;
    _dummy_vector->is_hidden = true;

    _dummy_box->selectable = false;
    _dummy_vector->selectable = false;

    _dummy_vector->set_scale(0.4f);

    add_object(_dummy_box);
    add_object(_dummy_vector);

    add_object(position_manipulator = new PositionManipulator());
    position_manipulator->is_hidden = true;
    position_manipulator->selectable = false;
}

Scene::~Scene() {
    for (auto obj : _objects)
        delete obj;
}

void Scene::add_object(Object* obj) {
    _objects.push_back(obj);
    obj->_scene = this;
    if (auto model = dynamic_cast<Model*>(obj)) {
        _models.push_back(model);
        model->_setup();
    }
}

void Scene::add_light(PointLight* light) {
    _light_sources.push_back(light);
}

void Scene::remove_object(Object* object) {
    cu::array::remove(_models, object);
    cu::array::remove(_objects, object);
    delete object;
}

void Scene::add_box(const Vector3& position, float size) {
    auto box = new BoxModel(Box(size));
    add_object(box);
    box->set_position(position);
}

void Scene::draw_box(const Vector3& position, float size) {
    _dummy_box->is_hidden = false;
    _dummy_box->set_scale(size);
    _dummy_box->set_position(position);
    _dummy_box->draw();
}

void Scene::update() {
    for (auto obj : _objects)
        obj->update();
    for (auto light : _light_sources)
        light->update();
}

void Scene::draw() {
    for (auto mod : _models)
        mod->draw();
    each_frame();
}

Model* Scene::select_model(const gm::Point& location) {

    auto ray = camera->cast_ray(location);

    Model* new_model = nullptr;

    for (auto model : _models) {
        if ((new_model = model->intersecting_ray(ray))) {
            break;
        }
    }

    if (new_model) {
        selected_model = new_model;
        for (auto model : _models)
            model->deselect();
        selected_model->is_selected = true;
    }

    return selected_model;
}

void Scene::add_ray(const gm::Ray& ray) {
    auto vector = new VectorModel();
    add_object(vector);
    vector->set_scale({ ray.length(), 0.1f, 0.1f });
    vector->set_position(ray.begin);
    vector->look_at(ray.direction_vector());
    vector->selectable = false;
}

void Scene::setup() {

}

void Scene::each_frame() {

}
