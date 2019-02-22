//
//  Plane.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/21/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Size.hpp"
#include "Model.hpp"

namespace scene {

class Plane : public Model {

public:

    const Size size;

    Plane(const Size& size = { 5, 5 });

};

}
