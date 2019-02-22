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

class Object;
class Model;

class Scene {

protected:

    std::vector<Model*> _models;

public:

    Camera* const camera;
    std::vector<Object*> _objects;

    Scene();
    virtual ~Scene();

    void add_object(Object*);

    void update();
    void draw();
    virtual void setup();
    virtual void each_frame();

};

}
