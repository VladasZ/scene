//
//  Camera.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Size.hpp"
#include "Flyable.hpp"

namespace scene {

class Camera : public Flyable {

    Matrix4            _view_matrix;
    Matrix4      _projection_matrix;
    Matrix4 _view_projection_matrix;

    Vector3 _target        ;
    Vector3 _up { 0, 0, 1 };

public:

    float fov    =     1.0f;
    float z_near =     0.1f;
    float z_far  = 10000.0f;

    Size resolution { 100, 100 };

    const Matrix4&            view_matrix() const;
    const Matrix4&      projection_matrix() const;
    const Matrix4& view_projection_matrix() const;

    void       set_target(const Vector3&);
    const Vector3& target() const        ;

    void move_orbit(const Point&);

private:

    void update_matrices() override;
    void update         () override;

    const Vector3& _direction() override;
};

}
