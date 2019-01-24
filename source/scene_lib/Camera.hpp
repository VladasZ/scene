//
//  Object.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 1/24/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Vector3.hpp"

namespace scene {

class Object {

public:

    Vector3 position;
    Vector3 rotation { 1, 0, 0 };

};

}
