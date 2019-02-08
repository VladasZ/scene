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
        data.push_back(ver.x);
        data.push_back(ver.y);
        data.push_back(ver.z);
        data.push_back(colors.back().r);
        data.push_back(colors.back().g);
        data.push_back(colors.back().b);
    }
}

ColoredMesh::~ColoredMesh() {

}
