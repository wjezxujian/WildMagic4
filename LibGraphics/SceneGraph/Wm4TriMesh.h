// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TRIMESH_H
#define WM4TRIMESH_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Geometry.h"
#include "Wm4IntArray.h"
#include "Wm4Triangle3.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM TriMesh : public Geometry
{
    WM4_DECLARE_RTTI;
    WM4_DECLARE_NAME_ID;
    WM4_DECLARE_STREAM;

public:
    // Construction and destruction.
    TriMesh (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer);
    virtual ~TriMesh ();

    // member access
    int GetTriangleQuantity () const;
    void GetModelTriangle (int i, Triangle3f& rkMTri) const;
    void GetWorldTriangle (int i, Triangle3f& rkWTri) const;

    void GenerateNormals ();

    // Picking support.  The pick record stores the index of any triangle
    // intersected by the ray.  It stores the barycentric coordinates of
    // the intersection point.  This allows the application to compute
    // interpolated vertex attributes as well as the actual point of
    // intersection.
    class WM4_GRAPHICS_ITEM PickRecord : public Geometry::PickRecord
    {
    public:
        PickRecord (TriMesh* pkIObject, float fT, int iTriangle, float fBary0,
            float fBary1, float fBary2);

        // Index of the triangle that is intersected by the ray.
        int Triangle;

        // Barycentric coordinates of the point of intersection.  If b0, b1,
        // and b2 are the values, then all are in [0,1] and b0+b1+b2=1.
        float Bary0, Bary1, Bary2;
    };

    // The origin and direction of the ray must be in world coordinates.  The
    // application is responsible for deleting the pick records in the array.
    virtual void DoPick (const Ray3f& rkRay, PickArray& rkResults);

protected:
    TriMesh ();

    // geometric updates
    virtual void UpdateModelNormals ();
};

WM4_REGISTER_STREAM(TriMesh);
typedef Pointer<TriMesh> TriMeshPtr;
#include "Wm4TriMesh.inl"

}

#endif
