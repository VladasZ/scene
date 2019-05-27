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
#include "PointLight.hpp"
#include "VectorModel.hpp"

using namespace gm;
using namespace scene;


Scene::Scene() : camera(new Camera()) {
    add_object(camera);

    _dummy_box    = new BoxModel();
    _dummy_vector = new VectorModel();

    _dummy_box   ->set_position({ 0, 0, 10000000000.0f });
    _dummy_vector->set_position({ 0, 0, 10000000000.0f });

    _dummy_vector->set_scale(0.4f);

    add_object(_dummy_box   );
    add_object(_dummy_vector);
}

Scene::~Scene() {
    for (auto obj : _objects)
        delete obj;
}

void Scene::add_object(Object* obj) {
    _objects.push_back(obj);
    obj->_scene = this;
    if (auto model = dynamic_cast<Model*>(obj))
        _models.push_back(model);
}

void Scene::add_light(PointLight* light) {
    _light_sources.push_back(light);
}

void Scene::add_box(const Vector3& position, float size) {
    auto box = new BoxModel(Box(size));
    add_object(box);
    box->set_position(position);
}

void Scene::draw_box(const Vector3& position, float size) {
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

    bool new_model = false;

    for (auto model : _models) {
        if (model->intersects_ray(ray)) {
            selected_model = model;
            new_model = true;
            break;
        }
    }

    if (new_model) {
        for (auto model : _models)
            model->selected = false;
        selected_model->selected = true;
    }

    return selected_model;
}

void Scene::setup() {

}

void Scene::each_frame() {

}
