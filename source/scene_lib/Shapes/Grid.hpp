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

    const Size size;
    const Size resolution;

    Grid(const Size& size = { 5, 5 }, const Size& resolution = { 20, 20 });
};

}
