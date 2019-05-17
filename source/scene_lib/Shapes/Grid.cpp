//
//  Grid.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "Mesh.hpp"
#include "Grid.hpp"

using namespace gm;
using namespace scene;

static Mesh* create_mesh(Size size, Size resolution) {

    Vertex::Array vertices;

    const auto width_min = - size.width / 2;
    const auto width_step = size.width / resolution.width;

    const auto height_min = - size.height / 2;
    const auto height_step = size.height / resolution.height;

    for (int i = 0; i <= resolution.width; i++) {
        vertices.emplace_back( Vector3 { width_min + width_step * i, height_min },              Vector3 { } );
        vertices.emplace_back( Vector3 { width_min + width_step * i, height_min + size.height}, Vector3 { } );
    }

    for (int i = 0; i <= resolution.height; i++) {
        vertices.emplace_back( Vector3 { width_min,              height_min + height_step * i }, Vector3 { } );
        vertices.emplace_back( Vector3 { width_min + size.width, height_min + height_step * i }, Vector3 { } );
    }

    return new Mesh(std::move(vertices));
}

Grid::Grid(const Size& size, const Size& resolution) :
    Model(create_mesh(size, resolution), Model::DrawMode::Triangles),
    size(size),
    resolution(resolution)
{ }

void Grid::draw() {


    Model::draw();

}
