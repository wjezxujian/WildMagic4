// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4STANDARDMESH_H
#define WM4STANDARDMESH_H

#include "Wm4GraphicsLIB.h"
#include "Wm4TriMesh.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM StandardMesh
{
public:
    StandardMesh (const Attributes& rkAttr, bool bInside = false,
        const Transformation* pkXFrm = 0);
    ~StandardMesh ();

    void SetTransformation (const Transformation& rkXFrm);
    const Transformation& GetTransformation () const;

    // Standard meshes.  Each mesh is centered at (0,0,0) and has an up-axis
    // of (0,0,1).  The other axes forming the coordinate system are (1,0,0)
    // and (0,1,0).  An application may transform the meshes as necessary.

    TriMesh* Rectangle (int iXSamples, int iYSamples, float fXExtent,
        float fYExtent);

    TriMesh* Disk (int iShellSamples, int iRadialSamples, float fRadius);

    TriMesh* Box (float fXExtent, float fYExtent, float fZExtent);

    TriMesh* Cylinder (int iAxisSamples, int iRadialSamples, float fRadius,
        float fHeight, bool bOpen);

    TriMesh* Sphere (int iZSamples, int iRadialSamples, float fRadius);

    TriMesh* Torus (int iCircleSamples, int iRadialSamples,
        float fOuterRadius, float fInnerRadius);

    // Platonic solids, inscribed in a unit sphere centered at (0,0,0).
    TriMesh* Tetrahedron ();
    TriMesh* Hexahedron ();
    TriMesh* Octahedron ();
    TriMesh* Dodecahedron ();
    TriMesh* Icosahedron ();

private:
    void CreatePlatonicNormals (VertexBuffer* pkVBuffer);
    void CreatePlatonicUVs (VertexBuffer* pkVBuffer);
    void ReverseTriangleOrder (int iTQuantity, int* aiIndex);
    void TransformData (VertexBuffer* pkVBuffer);

    Attributes m_kAttr;
    Transformation m_kXFrm;
    bool m_bInside;
    VertexBuffer* m_pkVBuffer;
    IndexBuffer* m_pkIBuffer;
};

}

#endif
