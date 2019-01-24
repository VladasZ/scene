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
    for (auto obj : objects)
        delete obj;
}
