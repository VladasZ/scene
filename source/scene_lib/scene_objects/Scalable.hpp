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

    Vector3 _scale = { 1.0f, 1.0f, 1.0f };
    Matrix4 _scale_matrix;

public:

    const Vector3& scale() const;

    void set_scale(float);
    void set_scale(const Vector3&);

    void update_matrices() override;

};

}
