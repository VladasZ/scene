//
//  Scene.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include <vector>

namespace scene {

class Camera;
class Object;

class Scene {
public:

    Camera* const camera;
    std::vector<Object*> objects;

    Scene();
    virtual ~Scene();
};

}
