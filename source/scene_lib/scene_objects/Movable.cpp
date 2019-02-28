//
//  Movable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Movable.hpp"

using namespace scene;

void Movable::stop() {
    velocity = { };
}

void Movable::update() {
    _position += velocity;
    update_matrices();
}
