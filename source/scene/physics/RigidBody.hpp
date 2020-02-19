//
//  RigidBody.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 02/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#ifdef USING_BULLET3D

#include "btBulletDynamicsCommon.h"

#include "Vector4.hpp"

namespace scene {

    class Physics3D;

    class RigidBody {

        friend Physics3D;

    public:

        enum class Shape {
            Box,
            Sphere,
        };

        static inline Physics3D* physics = nullptr;

    public:

        gm::Vector3 position;
        gm::Vector4 rotation;

        RigidBody(gm::Vector3 pos, float size, float mass, Shape shape);
        ~RigidBody();
        
        void update();

    protected:

        btRigidBody* body;
        btCollisionShape* shape;
        btDefaultMotionState* motion_state;

    };

}

#endif
