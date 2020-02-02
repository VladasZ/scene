//
//  Physics3D.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 01/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#ifdef USING_BULLET3D

#include "btBulletDynamicsCommon.h"

#include "Vector3.hpp"
#include "RigidBody.hpp"

namespace scene {

    class Physics3D {

    public:

        Physics3D();

        static inline gm::Vector3 ground_position;
        static inline gm::Vector3 box_position;

        void update(float interval);

        void update_rigid_body(RigidBody*);

        void add_rigid_body(RigidBody*);

    private:

        btDefaultCollisionConfiguration* collisionConfiguration;
        btCollisionDispatcher* dispatcher;
        btBroadphaseInterface* overlappingPairCache;
        btSequentialImpulseConstraintSolver* solver;
        btDiscreteDynamicsWorld* dynamicsWorld;

    };

}

#endif
