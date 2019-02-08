//
//  Model.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Rotatable.hpp"

namespace scene {

class Mesh;

class Model : public Rotatable {

public:

    enum DrawMode {
        Lines     = 0x0001,
        Triangles = 0x0004
    };

    class Drawer {
        friend Model;
    protected:
        Model* _model;
        virtual ~Drawer() = 0;
        virtual void _draw() const = 0;
    };

protected:

    DrawMode _draw_mode;

    Matrix4 _mvp_matrix;

    Mesh*  _mesh;

    Drawer* _drawer;

public:

    Model(Mesh*, DrawMode = Triangles);
    ~Model() override;

    Mesh* mesh() const;
    DrawMode draw_mode() const;

    void draw() const;

    const Matrix4& mvp_matrix() const;

private:

    void update_matrices() override;
};

}
