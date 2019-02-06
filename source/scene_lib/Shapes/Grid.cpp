//
//  Grid.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "Grid.hpp"
#include "ColoredMesh.hpp"

using namespace scene;

static Mesh* create_mesh(Size size, Size resolution) {

    std::vector<Vector3> vertices;

    const auto width_min = - size.width / 2;
    const auto width_step = size.width / resolution.width;

    const auto height_min = - size.height / 2;
    const auto height_step = size.height / resolution.height;

    for (int i = 0; i <= resolution.width; i++) {
        vertices.emplace_back( width_min + width_step * i, height_min );
        vertices.emplace_back( width_min + width_step * i, height_min + size.height );
    }

    for (int i = 0; i <= resolution.height; i++) {
        vertices.emplace_back( width_min,              height_min + height_step * i );
        vertices.emplace_back( width_min + size.width, height_min + height_step * i );
    }

    return new Mesh(vertices);
}

Grid::Grid(Size size, Size resolution) :
    Model(create_mesh(size, resolution)),
    size(size),
    resolution(resolution)
{ }
