//
//  Object.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Vector3.hpp"

namespace scene {

class Mesh;

class Object {

protected:

    Mesh* _mesh;

public:

    Vector3 position;
    Vector3 rotation { 1, 0, 0 };

    Object(Mesh*);
    virtual ~Object();

    Mesh* get_mesh() const;

};

}
