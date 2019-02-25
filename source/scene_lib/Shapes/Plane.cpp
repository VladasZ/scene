//
//  Plane.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/21/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Plane.hpp"
#include "ColoredMesh.hpp"

using namespace scene;

static Mesh* create_mesh(const Size& size) {
    return new ColoredMesh({{ 0, -size.width / 2,  size.height / 2 },
                            { 0,  size.width / 2,  size.height / 2 },
                            { 0,  size.width / 2, -size.height / 2 },
                            { 0, -size.width / 2, -size.height / 2 }}, { 0, 1, 2, 0, 2, 3 });
}

Plane::Plane(const Size& size) : Model(create_mesh(size)), size(size) {

}
