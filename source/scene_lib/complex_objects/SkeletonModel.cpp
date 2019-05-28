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


SkeletonModel::SkeletonModel(Skeleton* skeleton) : BoxModel(0.1f), _skeleton(skeleton) {

}

gm::Skeleton* SkeletonModel::skeleton() const {
    return _skeleton;
}

void SkeletonModel::update_skeleton() {
    remove_all_submodels();

    for (auto bone : _skeleton->all_bones()) {
        auto vector = new VectorModel();
        add_submodel(vector);
        vector->set_scale(bone->length());
        vector->set_position(bone->begin());
        vector->look_at(bone->direction());

        auto box = new BoxModel(Box(0.1f));
        add_submodel(box);
        box->set_scale(bone->length());
        box->set_position(bone->end());
    }
}
