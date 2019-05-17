//
//  Grid.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 2/6/19.
//  Copyright © 2019 VladasZ. All rights reserved.
//

#include "Size.hpp"
#include "Model.hpp"

namespace scene {

class Grid : public Model {

public:

    const gm::Size size;
    const gm::Size resolution;

    Grid(const gm::Size& size = { 5, 5 }, const gm::Size& resolution = { 20, 20 });

    void draw() override;
};

}
