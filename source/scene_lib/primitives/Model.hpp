//
//  Model.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Object.hpp"
#include "Matrix4.hpp"

namespace scene {

class Mesh;

class Model : public Object  {

protected:

    Matrix4 _model_matrix;
    Matrix4 _mvp_matrix;

    Mesh*  _mesh;

public:

    Model(Mesh*);
    ~Model() override;

    Mesh* mesh() const;

    const Matrix4& model_matrix() const;
    void calculate_model_matrix();

    const Matrix4& mvp_matrix() const;
    void calculate_mvp_matrix();
};

}
