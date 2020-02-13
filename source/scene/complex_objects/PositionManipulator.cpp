//
//  PositionManipulator.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Log.hpp"
#include "PositionManipulator.hpp"

using namespace gm;
using namespace scene;

PositionManipulator::PositionManipulator() : BoxModel(0.1f) {

    for (auto& arrow : arrows) {
        add_submodel(arrow = new VectorModel());
    }

    arrows.x->color = Color::red;
    arrows.y->color = Color::green;
    arrows.z->color = Color::blue;

    arrows.x->look_at({ 1, 0, 0 });
    arrows.y->look_at({ 0, 1, 0 });
    arrows.z->look_at({ 0, 0, 1 });

    box = new BoxModel(0.1f);
    box->color = Color::turquoise;
    add_submodel(box);

    color = Color::clear;

    respects_depth_buffer = false;

}

gm::Axis PositionManipulator::get_axis(Model* vector) const {
    if (vector == arrows.x) return Axis::X;
    if (vector == arrows.y) return Axis::Y;
    if (vector == arrows.z) return Axis::Z;
    Fatal("Invalid axis in PositionManipulator::get_position");
}
