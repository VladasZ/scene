//
//  Camera.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Size.hpp"
#include "Matrix4.hpp"

namespace scene {

class Camera {

    Matrix4 _view_matrix;
    Matrix4 _projection_matrix;

public:

    float fov    = 1;
    float z_near = 0.1f;
    float z_far  = 100.0f;

    Size resolution { 100, 100 };

    Vector3 position;
    Vector3 direction { 1, 0, 0 };

    const Matrix4& view_matrix() const;
    const Matrix4& projection_matrix() const;

    void update_view_matrix();
    void update_projection_matrix();

};

}
