//
//  Rotatable.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/8/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#pragma once

#include "Translatable.hpp"

namespace scene {

class Rotatable : public Translatable {

protected:

    gm::Vector3 _pivot;
    gm::Vector4 _rotation = { 1, 0, 0, 0 };
    gm::Matrix4 _rotation_matrix;

public:

    void look_at(const gm::Vector3&);

    const gm::Vector3& pivot() const;
    void set_pivot(const gm::Vector3&);

    const gm::Vector4& rotation() const;
    void set_rotation(const gm::Vector4&);

    const gm::Matrix4& rotation_matrix() const;
    void set_rotation_matrix(const gm::Matrix4&);

    void add_rotation(const gm::Matrix4&);

    void update_matrices() override;

};

}
