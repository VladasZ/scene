//
//  ColoredMesh.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <string>

#include "ColoredMesh.hpp"

using namespace scene;

ColoredMesh::ColoredMesh(const std::vector<Vector3>& vertices) : ColoredMesh(vertices, { }) {

}

ColoredMesh::ColoredMesh(const std::vector<Vector3>& vertices,
                         const std::vector<unsigned short>& indices) : Mesh(vertices, indices) {
    for (const auto& ver : vertices) {
        colors.push_back(Color::random());
        ver          .append_to_container(data);
        colors.back().append_to_container(data);
    }
}

ColoredMesh::~ColoredMesh() {

}
