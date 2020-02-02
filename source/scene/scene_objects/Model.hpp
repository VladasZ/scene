//
//  Model.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#ifdef USING_BULLET3D
#include "RigidBody.hpp"
#endif

#include "Color.hpp"
#include "Selectable.hpp"

class Image;

namespace scene {

    class Mesh;

    class Model : public Selectable {

    public:

        enum DrawMode {
            Lines     = 0x0001,
            Triangles = 0x0004,
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

        gm::Matrix4 _mvp_matrix;

        Mesh* _mesh;
        Image* _image;
        Drawer* _drawer;

        Model* _supermodel = nullptr;
        std::vector<Model*> _submodels;

    public:

        bool respects_depth_buffer = true;
        bool is_hidden = false;

        gm::Color color = gm::Color::green;

        Model(Mesh*, Image*);
        Model(Mesh*, DrawMode = Triangles);
        ~Model() override;

        Mesh* mesh() const;
        DrawMode draw_mode() const;

        void update() override;

        virtual void draw();
        virtual void update_rigid_body();

        void draw_normals();

        bool has_image() const;
        Image* image() const;

        Model* supermodel() const;

        void add_submodel(Model*);
        const std::vector<Model*>& submodels() const;

        void remove_all_submodels();

        const gm::Matrix4& mvp_matrix() const;

        Model* intersecting_ray(const gm::Ray&);

        void deselect();

        virtual void _setup();

#ifdef USING_BULLET3D
    protected:
        RigidBody* _rigid_body = nullptr;
    public:
        RigidBody* rigid_body();
        void add_rigid_body(float size, float mass, RigidBody::Shape shape);
#endif

    private:

        void update_matrices() override;
    };

}
