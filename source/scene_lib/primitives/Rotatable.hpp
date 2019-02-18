//
//  Rotatable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Translatable.hpp"

namespace scene {

class Rotatable : public Translatable {

protected:

    Vector3 _pivot;
    Vector4 _rotation = { 1, 0, 0, 0 };
    Matrix4 _rotation_matrix;

public:

    void look_at(const Vector3&);

    const Vector3& pivot() const;
    void set_pivot(const Vector3&);

    const Vector4& rotation() const;
    void set_rotation(const Vector4&);

    const Matrix4& rotation_matrix() const;

    void update_matrices() override;

};

}
