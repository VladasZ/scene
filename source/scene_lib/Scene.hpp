//
//  Scene.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <vector>

#include "Matrix4.hpp"

namespace scene {

class Camera;
class Object;

class Scene {

public:

    Camera* const camera;
    std::vector<Object*> _objects;

    Scene();
    virtual ~Scene();

    void add_object(Object*);

    void update();

};

}
