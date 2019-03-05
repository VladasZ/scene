//
//  Mesh.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include  "ColoredVertex.hpp"
#include "TexturedVertex.hpp"

namespace scene {

class Mesh {

public:

    using IndicesArray = std::vector<Vertex::Index>;

    enum Type {
        Plain   ,
        Colored ,
        Textured,
    };

private:

    const Type _type;

    const size_t _vertices_data_byte_size ;
    const size_t _vertices_data_float_size;

    void* _vertices_array;

    const IndicesArray _indices;

public:

    Mesh(        Vertex::Array&&                );
    Mesh(        Vertex::Array&&, IndicesArray&&);
    Mesh( ColoredVertex::Array&&, IndicesArray&&);
    Mesh(TexturedVertex::Array&&, IndicesArray&&);

    Type type() const;

    template <class T>
    const std::vector<T>& vertices() const {
        return *static_cast<const std::vector<T>*>(_vertices_array);
    }

    float* vertices_data           () const;
    size_t vertices_data_byte_size () const;
    size_t vertices_data_float_size() const;

    bool            has_indices() const;
    const IndicesArray& indices() const;

    bool is_plain   () const;
    bool is_colored () const;
    bool is_textured() const;

};

}
