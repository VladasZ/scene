//
//  Scene.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#ifdef USING_BULLET3D
#include "Physics3D.hpp"
#endif

#include "Model.hpp"
#include "Camera.hpp"
#include "Matrix4.hpp"
#include "PointLight.hpp"
#include "SceneConfig.hpp"
#include "PositionManipulator.hpp"

namespace scene {

class Scene {

    friend Model;

protected:

    Model* _dummy_box;
    Model* _dummy_vector;

#ifdef USING_BULLET3D
    Physics3D* _physics;
#endif

public:

    Model* selected_model = nullptr;

    PositionManipulator* position_manipulator;

    std::vector<PointLight*> _light_sources;

    Camera* const camera;

    std::vector<Model*> _models;
    std::vector<Object*> _objects;

    Scene();
    virtual ~Scene();

    void add_object(Object*);
    void add_light(PointLight*);

    void remove_object(Object*);

    void add_box(const gm::Vector3& = { }, float = 1);
    void draw_box(const gm::Vector3& = { }, float = 0.05f);

    void update();
    void draw();

    Model* select_model(const gm::Point& location);

    void add_ray(const gm::Ray&);

    virtual void _setup();
    virtual void each_frame();

};

}
