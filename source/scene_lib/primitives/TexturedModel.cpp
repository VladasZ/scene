//
//  TexturedModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/19/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "TexturedModel.hpp"

using namespace scene;

TexturedModel::TexturedModel(Image* texture, Mesh* mesh) : Model(mesh) {
    _texture = texture;
}
