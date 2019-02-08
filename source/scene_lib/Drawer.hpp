//
//  Drawer.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Model.hpp"

namespace scene {

class Drawer {

public:

    virtual ~Drawer();
    virtual Model::Drawer* init_model_drawer(Model*) = 0;

};

}
