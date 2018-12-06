// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef RIGIDTETRA_H
#define RIGIDTETRA_H

#include "Wm4RigidBody.h"
#include "Wm4TriMesh.h"
using namespace Wm4;

class RigidTetra : public RigidBodyf
{
public:
    RigidTetra (float fSize, float fMass, const Vector3f& rkPos,
        const Vector3f& rkLinMom, const Vector3f& rkAngMom);

    TriMeshPtr Mesh () const;
    float GetRadius () const;
    void GetVertices (Vector3f* akVertex) const;

    bool Moved;

private:
    TriMeshPtr m_spkMesh;
    float m_fRadius;
};

#endif

