// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TETRAHEDRON3_H
#define WM4TETRAHEDRON3_H

#include "Wm4FoundationLIB.h"
#include "Wm4Plane3.h"

namespace Wm4
{

template <class Real>
class Tetrahedron3
{
public:
    // The vertices are ordered so that the triangular faces are
    // counterclockwise when viewed by an observer outside the tetrahedron:
    //   face 0 = <V[0],V[2],V[1]>
    //   face 1 = <V[0],V[1],V[3]>
    //   face 2 = <V[0],V[3],V[2]>
    //   face 3 = <V[1],V[2],V[3]>

    // Construction.
    Tetrahedron3 ();  // uninitialized
    Tetrahedron3 (const Vector3<Real>& rkV0, const Vector3<Real>& rkV1,
        const Vector3<Real>& rkV2, const Vector3<Real>& rkV3);
    Tetrahedron3 (const Vector3<Real> akV[4]);

    // Get the vertex indices for the specified face.
    void GetFaceIndices (int iFace, int aiIndex[3]) const;

    // Construct the planes of the faces.  The planes have outer pointing
    // normal vectors.  The normals may be specified to be unit length.  The
    // plane indexing is the same as the face indexing mentioned previously.
    void GetPlanes (Plane3<Real> akPlane[4], bool bUnitLengthNormals) const;

    Vector3<Real> V[4];
};

#include "Wm4Tetrahedron3.inl"

typedef Tetrahedron3<float> Tetrahedron3f;
typedef Tetrahedron3<double> Tetrahedron3d;

}

#endif
