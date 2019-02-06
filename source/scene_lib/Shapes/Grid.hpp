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

    Size size;
    Size resolution;


    Grid(Size size = { 5, 5 }, Size resolution = { 20, 20 });

};

}
