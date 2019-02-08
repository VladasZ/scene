//
//  ColoredMesh.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/30/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <cstdint>

#include "Mesh.hpp"
#include "Color.hpp"
#include "Vector3.hpp"

namespace scene {

class ColoredMesh : public Mesh {

public:

    std::vector<Color> colors;
    std::vector<float> data;

    ColoredMesh(const std::vector<Vector3>&);
    ColoredMesh(const std::vector<Vector3>&, const std::vector<unsigned short>&);
    ~ColoredMesh() override;
};

}
