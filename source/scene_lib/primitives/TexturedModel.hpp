//
//  TexturedModel.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Image.hpp"
#include "Model.hpp"

namespace scene {

class TexturedModel : public Model {

    Image* _texture;

public:

    TexturedModel(Image*, Mesh*);
};

}
