//
//  Camera.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Size.hpp"
#include "Walkable.hpp"

namespace scene {

class Camera : public Walkable {

    Matrix4 _view_matrix;
    Matrix4 _projection_matrix;

    Vector3 _target;
    Vector3 _up { 0, 0, 1 };

public:

    float fov    = 1;
    float z_near = 0.1f;
    float z_far  = 100.0f;

    Size resolution { 100, 100 };

    const Matrix4& view_matrix() const;
    const Matrix4& projection_matrix() const;

    void move_orbit(const Point&);

private:

    void update_matrices() override;
    void update() override;

    const Vector3& _direction() override;
};

}
