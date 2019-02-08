//
//  Walkable.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Walkable.hpp"

using namespace scene;


void Walkable::walk(Direction direction) {

    Vector3 vel = _direction();
    Vector3 side = vel.cross({ 0, 0, 1 });
    vel.normalize();
    vel *= walking_speed;

    side.normalize();
    side *= walking_speed;

    if (direction == Direction::Forward)
        velocity = {  vel.x,  vel.y };

    if (direction == Direction::Back)
        velocity = { -vel.x, -vel.y };

    if (direction == Direction::Left)
        velocity = { -side.x, -side.y };

    if (direction == Direction::Right)
        velocity = {  side.x,  side.y };

}
