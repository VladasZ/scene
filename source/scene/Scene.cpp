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

void Scene::add_box(const gm::Vector3& position, const gm::Box& box, const gm::Color& color) {
    auto box_model = new BoxModel(box);
    box_model->color = color;
    add_object(box_model);
    box_model->edit_position() = { 3, 3, 3 };
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

gm::Axis Scene::select_axis(const gm::Ray& ray) {
    if (position_manipulator->is_hidden) return gm::Axis::None;

    for (auto arrow : position_manipulator->arrows) {
        if (auto hit = arrow->intersecting_ray(ray)) {
            return position_manipulator->get_axis(hit);
        }
    }

    return gm::Axis::None;
}

Model* Scene::select_model(const gm::Ray& ray) {

    position_manipulator->is_hidden = true;
    selected_model = nullptr;

    std::vector<Model*> hits;

    for (auto model : _models) {
        model->deselect();
        if (auto hit = model->intersecting_ray(ray)) {
            hits.push_back(hit);
        }
    }

    if (hits.empty()) return nullptr;

    Model* closest_to_camera;
    auto min_distance = std::numeric_limits<float>::max();

    for (auto model : hits) {
        auto distance = model->position().distance_to(camera->position());
        if (distance < min_distance) {
            min_distance = distance;
            closest_to_camera = model;
        }
    }

    selected_model = closest_to_camera;
    selected_model->is_selected = true;
    position_manipulator->edit_position() = selected_model->absolute_position();
    position_manipulator->is_hidden = false;

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
