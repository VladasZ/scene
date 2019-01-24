//
//  Object.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "Mesh.hpp"
#include "Object.hpp"

using namespace scene;

Object::Object(Mesh* mesh) : _mesh(mesh) {

}

Object::~Object() {
    delete _mesh;
}

Mesh* Object::mesh() const {
    return _mesh;
}
