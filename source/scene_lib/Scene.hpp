//
//  Scene.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include "Camera.hpp"
#include "Matrix4.hpp"
#include "SceneConfig.hpp"
#include "PositionManipulator.hpp"

namespace scene {

class Model;
class Object;
class PointLight;

class Scene {

    friend Model;

protected:

    Model* _dummy_box;
    Model* _dummy_vector;

    std::vector<Model*> _models;

public:


    Model* selected_model = nullptr;

    PositionManipulator* position_manipulator;

    std::vector<PointLight*> _light_sources;

    Camera* const camera;

    std::vector<Object*> _objects;

    Scene();
    virtual ~Scene();

    void add_object(Object*);
    void add_light(PointLight*);

    void add_box(const gm::Vector3&, float = 0.05f);
    void draw_box(const gm::Vector3&, float = 0.05f);

    void update();
    void draw();

    Model* select_model(const gm::Point& location);

    virtual void setup();
    virtual void each_frame();

};

}
