//
//  Object.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Matrix4.hpp"

namespace scene {

class Mesh;
class Scene;

class Object {

    friend Scene;

protected:

    Matrix4 _model_matrix;
    Matrix4 _mvp_matrix;

    Mesh*  _mesh;
    Scene* _scene;

public:

    Vector3 position;
    Vector3 rotation { 1, 0, 0 };

    Object(Mesh*);
    virtual ~Object();

    Mesh* mesh() const;

    const Matrix4& model_matrix() const;
    void calculate_model_matrix();

    const Matrix4& mvp_matrix() const;
    void calculate_mvp_matrix();

};

}
