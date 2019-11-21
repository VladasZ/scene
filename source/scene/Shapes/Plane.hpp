//
//  Plane.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/21/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <array>

#include "Size.hpp"
#include "Model.hpp"

namespace scene {

class Plane : public Model {

public:

    const gm::Size size;

    Plane(const gm::Size& size = { 5, 5 });
    Plane(const std::array<gm::Vector3, 4>&);

};

}
