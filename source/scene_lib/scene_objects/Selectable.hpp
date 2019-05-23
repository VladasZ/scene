//
//  Selectable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 5/22/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Ray.hpp"
#include "Box.hpp"
#include "Color.hpp"
#include "Scalable.hpp"

class Image;

namespace scene {

class Mesh;

class Selectable : public Scalable {

public:

    bool selected = false;
    bool selectable = true;

    const gm::Box bounding_box;

    Selectable(Mesh*);

    bool intersects_ray(const gm::Ray&) const;

};

}
