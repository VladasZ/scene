//
//  Plane.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/21/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Mesh.hpp"
#include "Plane.hpp"

using namespace scene;

static Mesh* create_mesh(const Size& size) {
    return new Mesh(ColoredVertex::Array {
                     {{ 0, -size.width / 2,  size.height / 2 }, { 1, 0, 0 }},
                     {{ 0,  size.width / 2,  size.height / 2 }, { 1, 0, 0 }},
                     {{ 0,  size.width / 2, -size.height / 2 }, { 1, 0, 0 }},
                     {{ 0, -size.width / 2, -size.height / 2 }, { 1, 0, 0 }}}, { 0, 1, 2, 0, 2, 3 });
}

Plane::Plane(const Size& size) : Model(create_mesh(size)), size(size) {
    look_at({ 0, 0, 1 });
}
