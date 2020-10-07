//
//  RigidBody.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 02/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#include "RigidBody.hpp"

#ifdef USING_BULLET3D

#include "Log.hpp"
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
    //TODO: CHECK
   // startTransform.setOrigin(cu::force_convert<btVector3>(pos));

    //using motionstate is recommended, it provides interpolation capabilities, and only synchronizes 'active' objects
    motion_state = new btDefaultMotionState(startTransform);
    btRigidBody::btRigidBodyConstructionInfo rbInfo(mass, motion_state, shape, localInertia);
    body = new btRigidBody(rbInfo);
    body->setRestitution(0.5);

    physics->add_rigid_body(this);

}

RigidBody::~RigidBody() {
    delete shape;
    delete body;
    delete motion_state;
}

void RigidBody::update() {
    physics->update_rigid_body(this);
}

void RigidBody::set_position(const gm::Vector3& position) {
    btTransform transform;
    body->getMotionState()->getWorldTransform(transform);
    _position = position;
    _position.flip_height();
    //TODO: CHECK
   // transform.setOrigin(cu::force_convert<btVector3>(_position));
    body->setWorldTransform(transform);
    motion_state->setWorldTransform(transform);
}

#endif
