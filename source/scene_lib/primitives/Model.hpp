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

class ColoredMesh;

class Model : public Object  {

protected:

    Matrix4 _model_matrix;
    Matrix4 _mvp_matrix;

    ColoredMesh*  _mesh;

public:

    Model(ColoredMesh*);
    ~Model() override;

    ColoredMesh* mesh() const;

    const Matrix4& model_matrix() const;
    void calculate_model_matrix();

    const Matrix4& mvp_matrix() const;
    void calculate_mvp_matrix();
};

}
