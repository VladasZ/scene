//
//  Scene.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>
using namespace std;

#include "Grid.hpp"
#include "Scene.hpp"
#include "Camera.hpp"

using namespace scene;


Scene::Scene() : camera(new Camera()) {
    add_object(camera);
}

Scene::~Scene() {
    for (auto obj : _objects)
        delete obj;
}

void Scene::add_object(Object* obj) {
    _objects.push_back(obj);
    obj->_scene = this;
    obj->update_matrices();

    if (auto model = dynamic_cast<Model*>(obj))
        _models.push_back(model);
}

void Scene::update() {
    for (auto obj : _objects)
        obj->update();
}

void Scene::draw() {
    for (auto mod : _models)
        mod->draw();
}

void Scene::setup() {
    add_object(new scene::Grid({ 10, 10 }, { 10, 10 }));
}
