//
//  VectorModel.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/27/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Mesh.hpp"
#include "VectorModel.hpp"

using namespace gm;
using namespace scene;

static Mesh* create_mesh() {
    return new Mesh {
        Vertex::Array {
            { { 0.800000f, 0.020000f, -0.020000f }, { 0.904508f, -0.301553f, 0.301431f }},
            { { 0.800000f, -0.020016f, -0.020017f }, { 0.904569f, 0.301401f, 0.301462f }},
            { { 0.800000f, -0.050000f, -0.050000f }, { 0.451064f, 0.631062f, 0.631062f }},
            { { 0.800000f, 0.050000f, -0.050000f }, { 0.451064f, -0.631062f, 0.631062f }},
            { { 0.800000f, -0.020016f, -0.020017f }, { 0.904569f, 0.301401f, 0.301462f }},
            { { 0.800000f, 0.020000f, -0.020000f }, { 0.904508f, -0.301553f, 0.301431f }},
            { { 0.000000f, 0.020016f, -0.019984f }, { 0.577319f, -0.577471f, 0.577197f }},
            { { -0.000004f, -0.019984f, -0.019984f }, { 0.577441f, 0.577227f, 0.577349f }},
            { { 0.800000f, -0.020016f, 0.019983f }, { 0.904508f, 0.301492f, -0.301492f }},
            { { 0.800000f, 0.019984f, 0.019983f }, { 0.904477f, -0.301523f, -0.301584f }},
            { { 0.800000f, 0.050000f, 0.050000f }, { 0.451064f, -0.631062f, -0.631062f }},
            { { 0.800000f, -0.050000f, 0.050000f }, { 0.451064f, 0.631062f, -0.631062f }},
            { { 0.800000f, -0.050000f, -0.050000f }, { 0.451064f, 0.631062f, 0.631062f }},
            { { 0.800000f, -0.050000f, 0.050000f }, { 0.451064f, 0.631062f, -0.631062f }},
            { { 1.000000f, 0.000000f, -0.000000f }, { -0.999969f, 0.000000f, 0.000000f }},
            { { 0.800000f, 0.050000f, 0.050000f }, { 0.451064f, -0.631062f, -0.631062f }},
            { { 0.800000f, 0.050000f, -0.050000f }, { 0.451064f, -0.631062f, 0.631062f }},
            { { 1.000000f, 0.000000f, -0.000000f }, { -0.999969f, 0.000000f, 0.000000f }},
            { { 0.800000f, 0.050000f, -0.050000f }, { 0.451064f, -0.631062f, 0.631062f }},
            { { 0.800000f, -0.050000f, -0.050000f }, { 0.451064f, 0.631062f, 0.631062f }},
            { { 1.000000f, 0.000000f, -0.000000f }, { -0.999969f, 0.000000f, 0.000000f }},
            { { 0.800000f, -0.050000f, 0.050000f }, { 0.451064f, 0.631062f, -0.631062f }},
            { { 0.800000f, 0.050000f, 0.050000f }, { 0.451064f, -0.631062f, -0.631062f }},
            { { 1.000000f, 0.000000f, -0.000000f }, { -0.999969f, 0.000000f, 0.000000f }},
            { { 0.000002f, -0.019984f, 0.020016f }, { 0.577319f, 0.577319f, -0.577380f }},
            { { -0.000004f, -0.019984f, -0.019984f }, { 0.577441f, 0.577227f, 0.577349f }},
            { { 0.000000f, 0.020016f, -0.019984f }, { 0.577319f, -0.577471f, 0.577197f }},
            { { 0.000002f, 0.020016f, 0.020016f }, { 0.577258f, -0.577319f, -0.577441f }},
            { { 0.800000f, 0.019984f, 0.019983f }, { 0.904477f, -0.301523f, -0.301584f }},
            { { 0.800000f, -0.020016f, 0.019983f }, { 0.904508f, 0.301492f, -0.301492f }},
            { { 0.000002f, -0.019984f, 0.020016f }, { 0.577319f, 0.577319f, -0.577380f }},
            { { 0.000002f, 0.020016f, 0.020016f }, { 0.577258f, -0.577319f, -0.577441f }},
            { { 0.800000f, -0.020016f, 0.019983f }, { 0.904508f, 0.301492f, -0.301492f }},
            { { 0.800000f, -0.020016f, -0.020017f }, { 0.904569f, 0.301401f, 0.301462f }},
            { { -0.000004f, -0.019984f, -0.019984f }, { 0.577441f, 0.577227f, 0.577349f }},
            { { 0.000002f, -0.019984f, 0.020016f }, { 0.577319f, 0.577319f, -0.577380f }},
            { { 0.800000f, 0.020000f, -0.020000f }, { 0.904508f, -0.301553f, 0.301431f }},
            { { 0.800000f, 0.019984f, 0.019983f }, { 0.904477f, -0.301523f, -0.301584f }},
            { { 0.000002f, 0.020016f, 0.020016f }, { 0.577258f, -0.577319f, -0.577441f }},
            { { 0.000000f, 0.020016f, -0.019984f }, { 0.577319f, -0.577471f, 0.577197f }}
        },{
            0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 1,
            8, 11, 1, 11, 2, 9, 0, 3, 9, 3, 10, 12, 13, 14, 15, 16, 17,
            18, 19, 20, 21, 22, 23, 24, 25, 26, 24, 26, 27, 28, 29, 30,
            28, 30, 31, 32, 33, 34, 32, 34, 35, 36, 37, 38, 36, 38, 39
        }};
}

VectorModel::VectorModel() : Model(create_mesh()) {

}

void VectorModel::visualize_vector(const gm::Vector3& vector, float scale) {
    position.reset();
    look_at(vector);
    set_scale({ vector.length(), scale, scale });
}

void VectorModel::visualize_line_segment(const gm::LineSegment& segment, float scale) {
    position = segment.begin;
    look_at(segment.end - segment.begin);
    set_scale({ segment.length(), scale, scale });
}
