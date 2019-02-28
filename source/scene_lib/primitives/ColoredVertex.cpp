//
//  ColoredVertex.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "ColoredVertex.hpp"

using namespace scene;

ColoredVertex::ColoredVertex(const Vector3& position, const Vector3& normal) : Vertex(position, normal), color(Color::random()) {

}

ColoredVertex::ColoredVertex(const Vector3& position, const Vector3& normal, const Color& color) : Vertex(position, normal), color(color) {

}
