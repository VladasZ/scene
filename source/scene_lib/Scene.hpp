//
//  Scene.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include <vector>

#include      "Camera.hpp"
#include     "Matrix4.hpp"
#include "SceneConfig.hpp"

namespace scene {

class Model     ;
class Object    ;
class PointLight;

class Scene {

    friend Model;

protected:

    Model*    _dummy_box;
    Model* _dummy_vector;

    std::vector<Model*>             _models;

public:

    std::vector<PointLight*> _light_sources;

    Camera* const camera;

    std::vector<Object*> _objects;

    Scene();
    virtual ~Scene();

    void add_object(Object    *);
    void add_light (PointLight*);

    void add_box (const Vector3&, float = 0.05f);
    void draw_box(const Vector3&, float = 0.05f);

    void update();
    void   draw();

    virtual void      setup();
    virtual void each_frame();

};

}
