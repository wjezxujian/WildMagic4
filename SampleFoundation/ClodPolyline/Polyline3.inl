// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline int Polyline3::GetVertexQuantity () const
{
    return m_iVQuantity;
}
//----------------------------------------------------------------------------
inline const Vector3f* Polyline3::GetVertices () const
{
    return m_akVertex;
}
//----------------------------------------------------------------------------
inline bool Polyline3::GetClosed () const
{
    return m_bClosed;
}
//----------------------------------------------------------------------------
inline int Polyline3::GetEdgeQuantity () const
{
    return m_iEQuantity;
}
//----------------------------------------------------------------------------
inline const int* Polyline3::GetEdges () const
{
    return m_aiEdge;
}
//----------------------------------------------------------------------------
inline int Polyline3::GetMinLevelOfDetail () const
{
    return m_iVMin;
}
//----------------------------------------------------------------------------
inline int Polyline3::GetMaxLevelOfDetail () const
{
    return m_iVMax;
}
//----------------------------------------------------------------------------
inline int Polyline3::GetLevelOfDetail () const
{
    return m_iVQuantity;
}
//----------------------------------------------------------------------------
