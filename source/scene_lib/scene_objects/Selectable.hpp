//
//  Selectable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Color.hpp"
#include "Scalable.hpp"

class Image;

namespace scene {

class Mesh;

class Selectable : public Scalable {

public:

    Selectable(Mesh*);

};

}
