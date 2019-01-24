//
//  Mesh.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <string>

#include "Mesh.hpp"

using namespace scene;

Mesh::Mesh(const std::vector<Vector3>& vertices, const std::vector<uint8_t>& indices) : vertices(vertices), indices(indices) {

}

const char* Mesh::to_string() const {
    static std::string string;
    for (auto& ver : vertices)
        string += std::string() + ver.to_string() + "\n";
    string.pop_back();
    return string.c_str();
}
