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

namespace scene {

class Box;
class Model;
class Object;

class Scene {

protected:

    Box* _dummy_box;

    std::vector<Model*> _models;

public:

    Camera* const camera;
    std::vector<Object*> _objects;

    Scene();
    virtual ~Scene();

    void add_object(Object*);
    void add_box(const Vector3&, float = 0.1f);
    void draw_box(const Vector3&);

    void update();
    void draw();
    virtual void setup();
    virtual void each_frame();

};

}
