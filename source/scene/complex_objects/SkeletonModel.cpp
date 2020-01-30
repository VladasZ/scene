//
//  SkeletonModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 29/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "VectorModel.hpp"
#include "SkeletonModel.hpp"

using namespace gm;
using namespace scene;

static const auto joint_size = 0.18f;

SkeletonModel::SkeletonModel(float scale) : BoxModel(Box(joint_size * scale)), scale(scale) {
//    for ([[maybe_unused]] auto bone : _skeleton->bones) {
//
//        auto vector = new VectorModel();
//        add_submodel(vector);
//        vector->selectable = false;
//
//        auto box = new BoxModel(Box(joint_size * scale));
//        add_submodel(box);
//
//        _vectors.push_back(vector);
//        _boxes.push_back(box);
//    }
//
//    update();
}

void SkeletonModel::add_bone(gm::Bone* bone) {

}

void SkeletonModel::update() {
    for (size_t i = 0; i < bones.size(); i++) {
        auto bone = bones[i];
        auto vector = _vectors[i];
        auto box = _boxes[i];
        vector->visualize_line_segment(bone->line_segment(), scale);
        box->set_position(bone->end());
    }
}

void SkeletonModel::_create_models_for_bone(gm::Bone* bone) {

}
