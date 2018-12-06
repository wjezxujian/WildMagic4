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
inline BSplineVolumef*& BoxSurface::Volume ()
{
    return m_pkVolume;
}
//----------------------------------------------------------------------------
inline const BSplineVolumef* BoxSurface::GetVolume () const
{
    return m_pkVolume;
}
//----------------------------------------------------------------------------
inline int BoxSurface::GetUSamples () const
{
    return m_iUSamples;
}
//----------------------------------------------------------------------------
inline int BoxSurface::GetVSamples () const
{
    return m_iVSamples;
}
//----------------------------------------------------------------------------
inline int BoxSurface::GetWSamples () const
{
    return m_iWSamples;
}
//----------------------------------------------------------------------------
