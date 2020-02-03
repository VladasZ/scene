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

    position_manipulator = new PositionManipulator();
    position_manipulator->_scene = this;
    position_manipulator->is_hidden = true;
    position_manipulator->selectable = false;
    static_cast<Model*>(position_manipulator)->_setup();

#ifdef USING_BULLET3D
    _physics = new Physics3D();
    RigidBody::physics = _physics;
#endif

}

Scene::~Scene() {
    for (auto obj : _objects) {
        delete obj;
    }
#ifdef USING_BULLET3D
    delete _physics;
#endif
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

void Scene::add_box(const gm::Box& b) {
    auto box = new BoxModel(b);
    box->color = gm::Color::red.with_alpha(0.1);
    box->set_scale(1.01);
    add_object(box);
}

void Scene::add_box(const Vector3& position, float size) {
    auto box = new BoxModel(Box(size));
    add_object(box);
    box->edit_position() = position;
}

void Scene::draw_box(const Vector3& position, float size) {
    _dummy_box->is_hidden = false;
    _dummy_box->set_scale(size);
    _dummy_box->edit_position() = position;
    _dummy_box->draw();
}

void Scene::update(float frame_time) {
#ifdef USING_BULLET3D
    _physics->update(frame_time);
#endif
    for (auto obj : _objects) {
        obj->update();
    }
    for (auto light : _light_sources) {
        light->update();
    }
    position_manipulator->update();
}

void Scene::draw() {
    for (auto model : _models) {
        model->draw();
    }
    position_manipulator->draw();
}

Model* Scene::select_model(const gm::Point& location) {

    auto ray = camera->cast_ray(location);

    position_manipulator->is_hidden = true;
    selected_model = nullptr;
    Model* new_model = nullptr;

    for (auto model : _models) {
        model->deselect();
        if (new_model) continue;
        new_model = model->intersecting_ray(ray);
    }

    if (new_model) {
        selected_model = new_model;
        selected_model->is_selected = true;
        position_manipulator->edit_position() = selected_model->position();
        position_manipulator->is_hidden = false;
    }

    return selected_model;
}

void Scene::add_ray(const gm::Ray& ray) {
    auto vector = new VectorModel();
    add_object(vector);
    vector->set_scale({ ray.length(), 0.1f, 0.1f });
    vector->edit_position() = ray.begin;
    vector->look_at(ray.direction_vector());
    vector->selectable = false;
}

void Scene::_setup() {

}
