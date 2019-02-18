//
//  TexturedMesh.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/18/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Mesh.hpp"
#include "Point.hpp"

namespace scene {

class TexturedMesh : public Mesh {

public:

    std::vector<Point> uv;
    std::vector<float> data;

    TexturedMesh(const std::vector<Vector3       >& vertices,
                 const std::vector<unsigned short>& indices,
                 const std::vector<Point         >& texture_coordinates);

};

}
