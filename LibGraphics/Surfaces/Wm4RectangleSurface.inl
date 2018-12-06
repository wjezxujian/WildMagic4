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
inline ParametricSurfacef*& RectangleSurface::Surface ()
{
    return m_pkSurface;
}
//----------------------------------------------------------------------------
inline const ParametricSurfacef* RectangleSurface::GetSurface () const
{
    return m_pkSurface;
}
//----------------------------------------------------------------------------
inline int RectangleSurface::GetUSamples () const
{
    return m_iUSamples;
}
//----------------------------------------------------------------------------
inline int RectangleSurface::GetVSamples () const
{
    return m_iVSamples;
}
//----------------------------------------------------------------------------
