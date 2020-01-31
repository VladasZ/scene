//
//  BoneModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 29/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "Scene.hpp"
#include "BoneModel.hpp"

using namespace gm;
using namespace scene;

BoneModel::BoneModel(float length) : BaseBone(length) {

}

void BoneModel::draw() {
    _joint->set_position(end());
    visualize_line_segment(line_segment());
    Model::draw();
}

void BoneModel::_setup() {
    Model::_setup();
    _scene->add_object(_joint = new BoxModel(0.1f));
    if (!is_root()) {
        return;
    }
    iterate_childred([&](BoneModel* child) {
       Log(child->to_string());
       _scene->add_object(child);
    });
}
