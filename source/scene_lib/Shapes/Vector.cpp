//
//  Vector.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Vector.hpp"
#include "ColoredMesh.hpp"

using namespace scene;

static ColoredMesh* create_mesh() {
    return new ColoredMesh {{
            { 0.8f,  0.02f, -0.02f },
            { 0.8f, -0.02f, -0.02f },
            { 0.8f, -0.05f, -0.05f },
            { 0.8f,  0.05f, -0.05f },
            { 0.0f,  0.02f, -0.02f },
            { 0.0f, -0.02f, -0.02f },
            { 0.8f, -0.02f,  0.02f },
            { 0.8f,  0.02f,  0.02f },
            { 0.8f,  0.05f,  0.05f },
            { 0.8f, -0.05f,  0.05f },
            { 1.0f,  0.00f, -0.00f },
            { 0.0f, -0.02f,  0.02f },
            { 0.0f,  0.02f,  0.02f }
        },{
            0,
            1,
            2,
            0,
            2,
            3,
            1,
            0,
            4,
            1,
            4,
            5,
            6,
            7,
            8,
            6,
            8,
            9,
            1,
            6,
            9,
            1,
            9,
            2,
            7,
            0,
            3,
            7,
            3,
            8,
            2,
            9,
            10,
            8,
            3,
            10,
            3,
            2,
            10,
            9,
            8,
            10,
            11,
            5,
            4,
            11,
            4,
            12,
            7,
            6,
            11,
            7,
            11,
            12,
            6,
            1,
            5,
            6,
            5,
            11,
            0,
            7,
            12,
            0,
            12,
            4
        }};
}

Vector::Vector() : Model(create_mesh()) {

}
