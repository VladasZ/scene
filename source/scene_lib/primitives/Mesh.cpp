//
//  Mesh.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <string>

#include "ArrayUtils.hpp"

#include "Mesh.hpp"

using namespace cu;
using namespace scene;

Mesh::Mesh(Vertex::Array&& vertices, IndicesArray&& indices) :
    _type(Type::Plain),
    _vertices_data_byte_size (array::bytes_size    (vertices)),
    _vertices_data_float_size(array::size_in<float>(vertices)),
    _indices(std::move(indices))
{
    _vertices_array = new Vertex::Array { };
    *static_cast<Vertex::Array*>(_vertices_array) = std::move(vertices);
}

Mesh::Mesh(ColoredVertex::Array&& vertices, IndicesArray&& indices) :
    _type(Type::Colored),
    _vertices_data_byte_size (array::bytes_size    (vertices)),
    _vertices_data_float_size(array::size_in<float>(vertices)),
    _indices(std::move(indices))
{
    _vertices_array = new ColoredVertex::Array { };
    *static_cast<ColoredVertex::Array*>(_vertices_array) = std::move(vertices);
}

Mesh::Mesh(TexturedVertex::Array&& vertices, IndicesArray&& indices) :
    _type(Type::Textured),
    _vertices_data_byte_size (array::bytes_size    (vertices)),
    _vertices_data_float_size(array::size_in<float>(vertices)),
    _indices(std::move(indices))
{
    _vertices_array = new TexturedVertex::Array { };
    *static_cast<TexturedVertex::Array*>(_vertices_array) = std::move(vertices);
}

Mesh::Type Mesh::type() const {
    return _type;
}

float* Mesh::vertices_data() const {
    return static_cast<std::vector<float>*>(_vertices_array)->data();
}

size_t Mesh::vertices_data_byte_size() const {
    return _vertices_data_byte_size;
}

size_t Mesh::vertices_data_float_size() const {
    return _vertices_data_float_size;
}

bool Mesh::has_indices() const {
    return _indices.size();
}

const Mesh::IndicesArray& Mesh::indices() const {
    return _indices;
}

bool Mesh::is_plain() const{
    return _type == Type::Plain;
}

bool Mesh::is_colored() const {
    return _type == Type::Colored;
}

bool Mesh::is_textured() const {
    return _type == Type::Textured;
}
