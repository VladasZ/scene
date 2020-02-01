//
//  Physics3D.cpp
//  scene
//
//  Created by Vladas Zakrevskis on 01/02/20.
//  Copyright © 2020 VladasZ. All rights reserved.
//

#ifdef USING_BULLET3D

#include "Log.hpp"
#include "Matrix4.hpp"
#include "Physics3D.hpp"

using namespace gm;
using namespace scene;


Physics3D::Physics3D() {

    ///collision configuration contains default setup for memory, collision setup. Advanced users can create their own configuration.
    collisionConfiguration = new btDefaultCollisionConfiguration();

    ///use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
    dispatcher = new btCollisionDispatcher(collisionConfiguration);

    ///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
    overlappingPairCache = new btDbvtBroadphase();

    ///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
    solver = new btSequentialImpulseConstraintSolver;

    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

    dynamicsWorld->setGravity(btVector3(0, -10, 0));

}

void Physics3D::update() {
    dynamicsWorld->stepSimulation(1.f / 60.f, 10);
}

void Physics3D::update_rigid_body(RigidBody* rigidBody) {
    btTransform trans;
    rigidBody->body->getMotionState()->getWorldTransform(trans);
    rigidBody->position = Vector3::force_convert(trans.getOrigin());
    rigidBody->position.flip_height();
}

void Physics3D::add_rigid_body(RigidBody* rigid_body) {
    dynamicsWorld->addRigidBody(rigid_body->body);
}

#endif