// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline bool BasicMesh::IsValid () const
{
    return m_bIsValid;
}
//----------------------------------------------------------------------------
inline int BasicMesh::GetVQuantity () const
{
    return m_iVQuantity;
}
//----------------------------------------------------------------------------
inline int BasicMesh::GetEQuantity () const
{
    return m_iEQuantity;
}
//----------------------------------------------------------------------------
inline int BasicMesh::GetTQuantity () const
{
    return m_iTQuantity;
}
//----------------------------------------------------------------------------
inline const void* BasicMesh::GetPoints () const
{
    return m_akPoint;
}
//----------------------------------------------------------------------------
inline const int* BasicMesh::GetIndices () const
{
    return m_aiIndex;
}
//----------------------------------------------------------------------------
inline const BasicMesh::Vertex* BasicMesh::GetVertices () const
{
    return m_akVertex;
}
//----------------------------------------------------------------------------
inline const BasicMesh::Edge* BasicMesh::GetEdges () const
{
    return m_akEdge;
}
//----------------------------------------------------------------------------
inline const BasicMesh::Triangle* BasicMesh::GetTriangles () const
{
    return m_akTriangle;
}
//----------------------------------------------------------------------------
