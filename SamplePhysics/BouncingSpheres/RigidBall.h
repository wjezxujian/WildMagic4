// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef RIGIDBALL_H
#define RIGIDBALL_H

#include "Wm4RigidBody.h"
#include "Wm4TriMesh.h"
using namespace Wm4;

class RigidBall : public RigidBodyf
{
public:
    RigidBall (float fRadius = 1.0f);

    TriMeshPtr& Mesh ();
    float GetRadius () const;

    bool Moved;

private:
    TriMeshPtr m_spkMesh;
    float m_fRadius;
};

#endif

