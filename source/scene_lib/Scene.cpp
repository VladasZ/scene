//
//  Scene.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>
using namespace std;

#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"

using namespace scene;


Scene::Scene() : camera(new Camera()) {

}

Scene::~Scene() {
    delete camera;
    for (auto obj : _objects)
        delete obj;
}

void Scene::add_object(Object* obj) {
    _objects.push_back(obj);
    obj->_scene = this;
}
