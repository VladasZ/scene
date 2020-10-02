//
//  RigidBody.hpp
//  scene
//
//  Created by Vladas Zakrevskis on 02/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#pragma once

#include "BulletInclude.hpp"

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

    protected:

        gm::Vector3 _position;
        gm::Vector4 _rotation;

    public:

        RigidBody(gm::Vector3 pos, float size, float mass, Shape shape);
        ~RigidBody();
        
        void update();

    public:

        const gm::Vector3& position() const { return _position; }
        const gm::Vector4& rotation() const { return _rotation; }

        void set_position(const gm::Vector3&);

    protected:

        btRigidBody* body;
        btCollisionShape* shape;
        btDefaultMotionState* motion_state;

    };

}

#endif
