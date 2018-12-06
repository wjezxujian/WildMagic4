// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4RIGIDBODY_H
#define WM4RIGIDBODY_H

#include "Wm4PhysicsLIB.h"
#include "Wm4Matrix3.h"
#include "Wm4Quaternion.h"

namespace Wm4
{

template <class Real>
class WM4_PHYSICS_ITEM RigidBody
{
public:
    // Construction and destruction.  The rigid body state is uninitialized.
    // Use the set functions to initialize the state before starting the
    // simulation.
    RigidBody ();
    virtual ~RigidBody ();

    // set/get position
    Vector3<Real>& Position ();

    // set rigid body state
    void SetMass (float fMass);
    void SetBodyInertia (const Matrix3<Real>& rkInertia);
    void SetPosition (const Vector3<Real>& rkPos);
    void SetQOrientation (const Quaternion<Real>& rkQOrient);
    void SetLinearMomentum (const Vector3<Real>& rkLinMom);
    void SetAngularMomentum (const Vector3<Real>& rkAngMom);
    void SetROrientation (const Matrix3<Real>& rkROrient);
    void SetLinearVelocity (const Vector3<Real>& rkLinVel);
    void SetAngularVelocity (const Vector3<Real>& rkAngVel);

    // get rigid body state
    Real GetMass () const;
    Real GetInverseMass () const;
    const Matrix3<Real>& GetBodyInertia () const;
    const Matrix3<Real>& GetBodyInverseInertia () const;
    Matrix3<Real> GetWorldInertia () const;
    Matrix3<Real> GetWorldInverseInertia () const;
    const Vector3<Real>& GetPosition () const;
    const Quaternion<Real>& GetQOrientation () const;
    const Vector3<Real>& GetLinearMomentum () const;
    const Vector3<Real>& GetAngularMomentum () const;
    const Matrix3<Real>& GetROrientation () const;
    const Vector3<Real>& GetLinearVelocity () const;
    const Vector3<Real>& GetAngularVelocity () const;

    // force/torque function format
    typedef Vector3<Real> (*Function)
    (
        Real,                    // time of application
        Real,                    // mass
        const Vector3<Real>&,    // position
        const Quaternion<Real>&, // orientation
        const Vector3<Real>&,    // linear momentum
        const Vector3<Real>&,    // angular momentum
        const Matrix3<Real>&,    // orientation
        const Vector3<Real>&,    // linear velocity
        const Vector3<Real>&     // angular velocity
    );

    // force and torque functions
    Function Force;
    Function Torque;

    // Runge-Kutta fourth-order differential equation solver
    void Update (Real fT, Real fDT);

protected:
    // constant quantities (matrices in body coordinates)
    Real m_fMass, m_fInvMass;
    Matrix3<Real> m_kInertia, m_kInvInertia;

    // state variables
    Vector3<Real> m_kPos;         // position
    Quaternion<Real> m_kQOrient;  // orientation
    Vector3<Real> m_kLinMom;      // linear momentum
    Vector3<Real> m_kAngMom;      // angular momentum

    // derived state variables
    Matrix3<Real> m_kROrient;    // orientation matrix
    Vector3<Real> m_kLinVel;     // linear velocity
    Vector3<Real> m_kAngVel;     // angular velocity
};

typedef RigidBody<float> RigidBodyf;
typedef RigidBody<double> RigidBodyd;

}

#endif
