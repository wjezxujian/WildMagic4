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
inline Curve3f*& TubeSurface::Medial ()
{
    return m_pkMedial;
}
//----------------------------------------------------------------------------
inline const Curve3f* TubeSurface::GetMedial () const
{
    return m_pkMedial;
}
//----------------------------------------------------------------------------
inline TubeSurface::RadialFunction& TubeSurface::Radial ()
{
    return m_oRadial;
}
//----------------------------------------------------------------------------
inline TubeSurface::RadialFunction TubeSurface::GetRadial () const
{
    return m_oRadial;
}
//----------------------------------------------------------------------------
inline Vector3f& TubeSurface::UpVector ()
{
    return m_kUpVector;
}
//----------------------------------------------------------------------------
inline const Vector3f& TubeSurface::GetUpVector () const
{
    return m_kUpVector;
}
//----------------------------------------------------------------------------
inline int TubeSurface::GetSliceSamples () const
{
    return m_iSliceSamples;
}
//----------------------------------------------------------------------------
inline int TubeSurface::Index (int iS, int iM)
{
    return iS + (m_iSliceSamples+1)*iM;
}
//----------------------------------------------------------------------------
