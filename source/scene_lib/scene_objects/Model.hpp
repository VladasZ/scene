//
//  Model.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Scalable.hpp"

class Image;

namespace scene {

class Mesh;

class Model : public Scalable {

public:

    enum DrawMode {
        Lines     = 0x0001,
        Triangles = 0x0004,
    };

    class Drawer {
        friend Model;
    protected:
        Model* _model;
        virtual ~Drawer()          = 0;
        virtual void _draw() const = 0;
    };

protected:

    DrawMode _draw_mode;

    gm::Matrix4 _model_matrix;
    gm::Matrix4   _mvp_matrix;

    Mesh  *   _mesh;
    Image *  _image;
    Drawer* _drawer;

public:

    bool is_transparent = false;

     Model(Mesh*, Image*              );
     Model(Mesh*, DrawMode = Triangles);
    ~Model()                   override;

    Mesh*         mesh() const;
    DrawMode draw_mode() const;

    void draw        ();
    void draw_normals();

    bool has_image() const;
    Image*   image() const;

    const gm::Matrix4& model_matrix() const;
    const gm::Matrix4&   mvp_matrix() const;

private:

    void update_matrices() override;
};

}
