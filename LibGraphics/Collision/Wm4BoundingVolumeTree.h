// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4BOUNDINGVOLUMETREE_H
#define WM4BOUNDINGVOLUMETREE_H

#include "Wm4GraphicsLIB.h"
#include "Wm4BoundingVolume.h"
#include "Wm4Line3.h"
#include "Wm4TriMesh.h"

namespace Wm4
{

class WM4_GRAPHICS_ITEM BoundingVolumeTree
{
public:
    // abstract base class.
    virtual ~BoundingVolumeTree ();

    // tree topology
    BoundingVolumeTree* GetLChild ();
    BoundingVolumeTree* GetRChild ();
    bool IsInteriorNode () const;
    bool IsLeafNode () const;

    // member access
    const TriMesh* GetMesh () const;
    const BoundingVolume* GetWorldBound () const;
    int GetTriangleQuantity () const;
    int GetTriangle (int i) const;
    const int* GetTriangles () const;

    void UpdateWorldBound ();

protected:
    BoundingVolumeTree (const TriMesh* pkMesh);
    BoundingVolumeTree (int eBVType, const TriMesh* pkMesh,
        int iMaxTrisPerLeaf = 1, bool bStoreInteriorTris = false);

    void BuildTree (int eBVType, int iMaxTrisPerLeaf, bool bStoreInteriorTris,
        const Vector3f* akCentroid, int i0, int i1, int* aiISplit,
        int* aiOSplit);

    static void SplitTriangles (const Vector3f* akCentroid, int i0, int i1,
        int* aiISplit, int& rj0, int& rj1, int* aiOSplit,
        const Line3f& rkLine);

    // for quick-sort of centroid projections on axes
    class WM4_GRAPHICS_ITEM ProjectionInfo
    {
    public:
        int m_iTriangle;
        float m_fProjection;
    };
    static int Compare (const void* pvElement0, const void* pvElement1);

    // model bounding volume factory
    typedef BoundingVolume* (*CreatorM)(const TriMesh*,int,int,int*,Line3f&);
    static CreatorM ms_aoCreateModelBound[BoundingVolume::BV_QUANTITY];

    // world bounding volume factory
    typedef BoundingVolume* (*CreatorW)(void);
    static CreatorW ms_aoCreateWorldBound[BoundingVolume::BV_QUANTITY];

    // mesh and bounds
    const TriMesh* m_pkMesh;
    BoundingVolumePtr m_spkModelBound;
    BoundingVolumePtr m_spkWorldBound;

    // binary tree representation
    BoundingVolumeTree* m_pkLChild;
    BoundingVolumeTree* m_pkRChild;

    // If bStoreInteriorTris is set to 'false' in the constructor, the
    // interior nodes set the triangle quantity to zero and the array to null.
    // Leaf nodes set the quantity to the number of triangles at that node (1
    // if iMaxTrianglesPerLeaf was set to 1) and allocate an array of
    // triangle indices that are relative to the input mesh of the top level
    // constructor.
    //
    // If bStoreInteriorTris is set to 'true', the interior nodes also save
    // the triangle quantity and array of triangle indices for the mesh that
    // the node represents.
    int m_iTriangleQuantity;
    int* m_aiTriangle;

#ifdef _DEBUG_TEST
    // Checks to see if the vertices corresponding to the triangle mesh at
    // at each tree node are contained by the model space bounding volume.
    // The call is only made when _DEBUG_TEST has been defined *and* when
    // bStoreInteriorTris is set to 'true'.
    bool ContainsLeafData (const VertexBuffer* pkVBuffer, const int* aiIndex,
        float fEpsilon) const;
#endif
};

#include "Wm4BoundingVolumeTree.inl"

}

#endif
