//
//  PositionManipulator.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "XYZPack.hpp"
#include "BoxModel.hpp"
#include "VectorModel.hpp"

namespace scene {

class PositionManipulator : public BoxModel {

public:

    cu::XYZPack<VectorModel*> arrows = nullptr;

    PositionManipulator();


private:

    void _setup() override;

};

}
