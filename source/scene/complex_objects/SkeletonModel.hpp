//
//  SkeletonModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 29/01/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "Bone.hpp"
#include "BoxModel.hpp"
#include "VectorModel.hpp"

namespace scene {

class SkeletonModel : public BoxModel {

    std::vector<gm::Bone*> bones;

    std::vector<BoxModel*> _boxes;
    std::vector<VectorModel*> _vectors;

public:

    const float scale;

    SkeletonModel(float scale = 1);

    void add_bone(gm::Bone*);

    void update();

protected:

    void _create_models_for_bone(gm::Bone*);

};

}
