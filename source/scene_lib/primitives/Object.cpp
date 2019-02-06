//
//  Object.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "ColoredMesh.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Object.hpp"

using namespace scene;

Object::~Object() {

}

void Object::stop() {
    velocity = { };
}

void Object::update() {
    position += velocity;
}
