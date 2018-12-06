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
inline Ergb8 RayTrace::GetRendered (int iX, int iY)
{
    return (*m_pkRender)(iX,iY);
}
//----------------------------------------------------------------------------
inline Ergb8 RayTrace::GetRendered (int i)
{
    return (*m_pkRender)[i];
}
//----------------------------------------------------------------------------
inline float& RayTrace::Frame (int iY, int iX)
{
    return m_aafFrame[iY][iX];
}
//----------------------------------------------------------------------------

