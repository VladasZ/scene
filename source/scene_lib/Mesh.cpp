//
//  Mesh.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <iostream>

#include "Mesh.hpp"

using namespace scene;

Mesh::Mesh(const std::vector<Vector3>& vertices, const std::vector<uint8_t>& indices) : vertices(vertices), indices(indices) {

}
