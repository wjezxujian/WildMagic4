// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4TriMesh.h"
#include "Wm4IntrRay3Triangle3.h"
using namespace Wm4;

WM4_IMPLEMENT_RTTI(Wm4,TriMesh,Geometry);
WM4_IMPLEMENT_STREAM(TriMesh);
WM4_IMPLEMENT_DEFAULT_STREAM(TriMesh,Geometry);
WM4_IMPLEMENT_DEFAULT_NAME_ID(TriMesh,Geometry);

//----------------------------------------------------------------------------
TriMesh::TriMesh ()
{
    Type = GT_TRIMESH;
}
//----------------------------------------------------------------------------
TriMesh::TriMesh (VertexBuffer* pkVBuffer, IndexBuffer* pkIBuffer)
    :
    Geometry(pkVBuffer,pkIBuffer)
{
    Type = GT_TRIMESH;
}
//----------------------------------------------------------------------------
TriMesh::~TriMesh ()
{
}
//----------------------------------------------------------------------------
void TriMesh::GetModelTriangle (int i, Triangle3f& rkMTri) const
{
    assert(0 <= i && 3*i < IBuffer->GetIndexQuantity());
    int* aiIndex = IBuffer->GetData();
    assert(aiIndex);
    int* piIndex = &aiIndex[3*i];
    rkMTri.V[0] = VBuffer->Position3(*piIndex++);
    rkMTri.V[1] = VBuffer->Position3(*piIndex++);
    rkMTri.V[2] = VBuffer->Position3(*piIndex  );
}
//----------------------------------------------------------------------------
void TriMesh::GetWorldTriangle (int i, Triangle3f& rkWTri) const
{
    assert(0 <= i && 3*i < IBuffer->GetIndexQuantity());
    int* aiIndex = IBuffer->GetData();
    assert(aiIndex);
    int* piIndex = &aiIndex[3*i];
    rkWTri.V[0] = World.ApplyForward(VBuffer->Position3(*piIndex++));
    rkWTri.V[1] = World.ApplyForward(VBuffer->Position3(*piIndex++));
    rkWTri.V[2] = World.ApplyForward(VBuffer->Position3(*piIndex  ));
}
//----------------------------------------------------------------------------
void TriMesh::GenerateNormals ()
{
    if (!VBuffer->GetAttributes().HasNormal())
    {
        Attributes kAttr = VBuffer->GetAttributes();
        kAttr.SetNChannels(3);
        VertexBuffer* pkVBufferPlusNormals = WM4_NEW VertexBuffer(kAttr,
            VBuffer->GetVertexQuantity());
        int iChannels;
        float* afData = pkVBufferPlusNormals->GetData();
        VBuffer->BuildCompatibleArray(kAttr,false,iChannels,afData);
        assert(iChannels == pkVBufferPlusNormals->GetChannelQuantity());
        VBuffer = pkVBufferPlusNormals;
    }

    UpdateModelNormals();
}
//----------------------------------------------------------------------------
void TriMesh::UpdateModelNormals ()
{
    // Calculate normals from vertices by weighted averages of facet planes
    // that contain the vertices.
    if (!VBuffer->GetAttributes().HasNormal())
    {
        return;
    }

    int iVQuantity = VBuffer->GetVertexQuantity();
    int i;
    for (i = 0; i < iVQuantity; i++)
    {
        VBuffer->Normal3(i) = Vector3f::ZERO;
    }

    int iTQuantity = IBuffer->GetIndexQuantity()/3;
    int* piIndex = IBuffer->GetData();
    for (i = 0; i < iTQuantity; i++)
    {
        // get vertex indices
        int iV0 = *piIndex++;
        int iV1 = *piIndex++;
        int iV2 = *piIndex++;

        // get vertices
        Vector3f& rkV0 = VBuffer->Position3(iV0);
        Vector3f& rkV1 = VBuffer->Position3(iV1);
        Vector3f& rkV2 = VBuffer->Position3(iV2);

        // compute the normal (length provides the weighted sum)
        Vector3f kEdge1 = rkV1 - rkV0;
        Vector3f kEdge2 = rkV2 - rkV0;
        Vector3f kNormal = kEdge1.Cross(kEdge2);

        VBuffer->Normal3(iV0) += kNormal;
        VBuffer->Normal3(iV1) += kNormal;
        VBuffer->Normal3(iV2) += kNormal;
    }

    for (i = 0; i < iVQuantity; i++)
    {
        VBuffer->Normal3(i).Normalize();
    }
}
//----------------------------------------------------------------------------
TriMesh::PickRecord::PickRecord (TriMesh* pkIObject, float fT, int iTriangle,
    float fBary0, float fBary1, float fBary2)
    :
    Geometry::PickRecord(pkIObject,fT)
{
    Triangle = iTriangle;
    Bary0 = fBary0;
    Bary1 = fBary1;
    Bary2 = fBary2;
}
//----------------------------------------------------------------------------
void TriMesh::DoPick (const Ray3f& rkRay, PickArray& rkResults)
{
    if (WorldBound->TestIntersection(rkRay))
    {
        // convert the ray to model-space coordinates
        Ray3f kRay(World.ApplyInverse(rkRay.Origin),
            World.InvertVector(rkRay.Direction));

        // compute intersections with the model-space triangles
        int iTQuantity = IBuffer->GetIndexQuantity()/3;
        const int* piConnect = IBuffer->GetData();
        for (int i = 0; i < iTQuantity; i++)
        {
            int iV0 = *piConnect++;
            int iV1 = *piConnect++;
            int iV2 = *piConnect++;

            Triangle3f kTriangle(VBuffer->Position3(iV0),
                VBuffer->Position3(iV1),VBuffer->Position3(iV2));

            IntrRay3Triangle3f kIntr(kRay,kTriangle);
            if (kIntr.Find())
            {
                rkResults.push_back(WM4_NEW PickRecord(this,kIntr.GetRayT(),i,
                    kIntr.GetTriB0(),kIntr.GetTriB1(),kIntr.GetTriB2()));
            }
        }
    }
}
//----------------------------------------------------------------------------
