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

Mesh::Mesh(const std::vector<Vector3>& vertices)
    : vertices(vertices), middle_point(Vector3::middle_point(vertices)) { }

Mesh::Mesh(const std::vector<Vector3>& vertices, const std::vector<unsigned short>& indices)
    : vertices(vertices), indices(indices), middle_point(Vector3::middle_point(vertices))  { }

Mesh::~Mesh() { }

const char* Mesh::to_string() const {
    static std::string string;
    for (auto& ver : vertices)
        string += std::string() + ver.to_string() + "\n";
    string += "\n";
    string.pop_back();
    for (auto& ind : indices)
        string += std::string() + std::to_string(ind) + "\n";
    return string.c_str();
}
