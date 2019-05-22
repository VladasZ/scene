//
//  BoxModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "Mesh.hpp"
#include "BoxModel.hpp"

using namespace gm;
using namespace scene;

static Mesh* create_mesh(float length, float width, float height) {

    const float length_2 = length / 2;
    const float  width_2 = width  / 2;
    const float height_2 = height / 2;
    return new Mesh {
        Vertex::Array {
            // front
            {{ -length_2, -width_2,  height_2 }, { -1, -1,  1 }},
            {{  length_2, -width_2,  height_2 }, {  1, -1,  1 }},
            {{  length_2,  width_2,  height_2 }, {  1,  1,  1 }},
            {{ -length_2,  width_2,  height_2 }, { -1,  1,  1 }},
            // back
            {{ -length_2, -width_2, -height_2 }, { -1, -1, -1 }},
            {{  length_2, -width_2, -height_2 }, {  1, -1, -1 }},
            {{  length_2,  width_2, -height_2 }, {  1,  1, -1 }},
            {{ -length_2,  width_2, -height_2 }, { -1,  1, -1 }}
        },{
            // front
            0, 1, 2,
            2, 3, 0,
            // right
            1, 5, 6,
            6, 2, 1,
            // back
            7, 6, 5,
            5, 4, 7,
            // left
            4, 0, 3,
            3, 7, 4,
            // bottom
            4, 5, 1,
            1, 0, 4,
            // top
            3, 2, 6,
            6, 7, 3
        }};
}

BoxModel::BoxModel(float size) : BoxModel(size, size, size) {

}

BoxModel::BoxModel(float length, float width, float height) :
    Model(create_mesh(length, width, height)),
    length(length),
    width(width),
    height(height)
{ }
