//
//  SkeletonModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/28/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "VectorModel.hpp"
#include "SkeletonModel.hpp"

using namespace gm;
using namespace scene;

static const auto joint_size = 0.18f;

SkeletonModel::SkeletonModel(Skeleton* skeleton) : BoxModel(joint_size), _skeleton(skeleton) {
    for ([[maybe_unused]] auto bone : _skeleton->bones) {

        auto vector = new VectorModel();
        add_submodel(vector);
        vector->selectable = false;

        auto box = new BoxModel(Box(joint_size));
        add_submodel(box);

        _vectors.push_back(vector);
        _boxes.push_back(box);
    }

    update_skeleton();
}

gm::Skeleton* SkeletonModel::skeleton() const {
    return _skeleton;
}

void SkeletonModel::update_skeleton() {
    for (size_t i = 0; i < _skeleton->bones.size(); i++) {
        auto bone = _skeleton->bones[i];
        auto vector = _vectors[i];
        auto box = _boxes[i];
        vector->visualize_line_segment(bone->line_segment());
        box->set_position(bone->end());
    }
}
