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

}

gm::Skeleton* SkeletonModel::skeleton() const {
    return _skeleton;
}

void SkeletonModel::update_skeleton() {
    remove_all_submodels();

    for (auto bone : _skeleton->all_bones()) {
        auto vector = new VectorModel();
        add_submodel(vector);
        vector->set_scale( { bone->length(), 1, 1 });
        vector->set_position(bone->begin());
        vector->look_at(bone->direction());
        vector->selectable = false;

        auto box = new BoxModel(Box(joint_size));
        add_submodel(box);
        box->set_position(bone->end());
    }
}
