//
//  RigidBody.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 02/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#ifdef USING_BULLET3D

#include "Log.hpp"
#include "RigidBody.hpp"
#include "Physics3D.hpp"

using namespace gm;
using namespace scene;

RigidBody::RigidBody(gm::Vector3 pos, float size, float mass, RigidBody::Shape shape_type) {

    if (physics == nullptr) {
        Fatal("Physics is not set for rigid body");
    }
    //create a dynamic rigidbody

    if (shape_type == RigidBody::Shape::Box) {
        shape = new btBoxShape(btVector3(size / 2, size / 2, size / 2));
    }
    else {
        shape = new btSphereShape(size / 2);
    }

    /// Create Dynamic Objects
    btTransform startTransform;
    startTransform.setIdentity();

    //rigidbody is dynamic if and only if mass is non zero, otherwise static
    bool isDynamic = (mass != 0.f);

    btVector3 localInertia(0, 0, 0);
    if (isDynamic) {
        shape->calculateLocalInertia(mass, localInertia);
    }

    pos.flip_height();
    startTransform.setOrigin(pos.force_create<btVector3>());

    //using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
    btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, myMotionState, shape, localInertia);
    body = new btRigidBody(rbInfo);
    body->setRestitution(0.5);

    physics->add_rigid_body(this);

}

void RigidBody::update() {
    physics->update_rigid_body(this);
}

#endif
