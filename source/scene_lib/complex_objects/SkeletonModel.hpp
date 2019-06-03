//
//  SkeletonModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/28/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Skeleton.hpp"
#include "BoxModel.hpp"
#include "VectorModel.hpp"

namespace scene {

class SkeletonModel : public BoxModel {

    gm::Skeleton* _skeleton;

    std::vector<BoxModel*> _boxes;
    std::vector<VectorModel*> _vectors;

public:

    SkeletonModel(gm::Skeleton*);

    gm::Skeleton* skeleton() const;

    void update_skeleton();

};

}
