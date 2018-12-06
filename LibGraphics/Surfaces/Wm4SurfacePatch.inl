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
inline float SurfacePatch::GetUMin () const
{
    return m_fUMin;
}
//----------------------------------------------------------------------------
inline float SurfacePatch::GetUMax () const
{
    return m_fUMax;
}
//----------------------------------------------------------------------------
inline float SurfacePatch::GetVMin () const
{
    return m_fVMin;
}
//----------------------------------------------------------------------------
inline float SurfacePatch::GetVMax () const
{
    return m_fVMax;
}
//----------------------------------------------------------------------------
inline bool SurfacePatch::IsRectangular () const
{
    return m_bRectangular;
}
//----------------------------------------------------------------------------
