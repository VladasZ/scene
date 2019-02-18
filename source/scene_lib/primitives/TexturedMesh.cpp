//
//  TexturedMesh.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/18/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TexturedMesh.hpp"

using namespace scene;

TexturedMesh::TexturedMesh(const std::vector<Vector3       >& vertices,
                           const std::vector<unsigned short>& indices,
                           const std::vector<Point         >& texture_coordinates) : Mesh(vertices, indices) {
    uv = texture_coordinates;


}
