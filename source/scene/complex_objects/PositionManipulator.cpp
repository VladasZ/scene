//
//  PositionManipulator.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "PositionManipulator.hpp"

using namespace gm;
using namespace scene;

PositionManipulator::PositionManipulator() : BoxModel(0.1f) {
    color = Color::turquoise;

    add_submodel(arrows.x = new VectorModel());
    add_submodel(arrows.y = new VectorModel());
    add_submodel(arrows.z = new VectorModel());

    arrows.x->color = Color::red;
    arrows.y->color = Color::green;
    arrows.z->color = Color::blue;

    arrows.x->look_at({ 1, 0, 0 });
    arrows.y->look_at({ 0, 1, 0 });
    arrows.z->look_at({ 0, 0, 1 });

    box = new BoxModel(0.1f);
    box->color = Color::turquoise;
    add_submodel(box);

    respects_depth_buffer = false;

}
