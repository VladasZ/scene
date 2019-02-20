//
//  Scalable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/20/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Rotatable.hpp"

namespace scene {

class Scalable : public Rotatable {

protected:

    float _scale = 1.0f;
    Matrix4 _scale_matrix;

public:

    float scale() const;
    void set_scale(float);

    void update_matrices() override;

};

}
