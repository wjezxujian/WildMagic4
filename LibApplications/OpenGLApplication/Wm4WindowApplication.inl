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
inline const char* WindowApplication::GetWindowTitle () const
{
    return m_acWindowTitle;
}
//----------------------------------------------------------------------------
inline int WindowApplication::GetXPosition () const
{
    return m_iXPosition;
}
//----------------------------------------------------------------------------
inline int WindowApplication::GetYPosition () const
{
    return m_iYPosition;
}
//----------------------------------------------------------------------------
inline int WindowApplication::GetWidth () const
{
    return m_iWidth;
}
//----------------------------------------------------------------------------
inline int WindowApplication::GetHeight () const
{
    return m_iHeight;
}
//----------------------------------------------------------------------------
inline Renderer* WindowApplication::GetRenderer ()
{
    return m_pkRenderer;
}
//----------------------------------------------------------------------------
inline void WindowApplication::SetRenderer (Renderer* pkRenderer)
{
    m_pkRenderer = pkRenderer;
}
//----------------------------------------------------------------------------
inline void WindowApplication::SetWindowID (int iWindowID)
{
    m_iWindowID = iWindowID;
}
//----------------------------------------------------------------------------
inline int WindowApplication::GetWindowID () const
{
    return m_iWindowID;
}
//----------------------------------------------------------------------------
inline bool WindowApplication::OnPrecreate ()
{
    // stub for derived classes
    return true;
}
//----------------------------------------------------------------------------
inline void WindowApplication::OnDisplay ()
{
    // stub for derived classes
}
//----------------------------------------------------------------------------
inline void WindowApplication::OnIdle ()
{
    // stub for derived classes
}
//----------------------------------------------------------------------------
inline bool WindowApplication::OnKeyDown (unsigned char, int, int)
{
    // stub for derived classes
    return false;
}
//----------------------------------------------------------------------------
inline bool WindowApplication::OnKeyUp (unsigned char, int, int)
{
    // stub for derived classes
    return false;
}
//----------------------------------------------------------------------------
inline bool WindowApplication::OnSpecialKeyDown (int, int, int)
{
    // stub for derived classes
    return false;
}
//----------------------------------------------------------------------------
inline bool WindowApplication::OnSpecialKeyUp (int, int, int)
{
    // stub for derived classes
    return false;
}
//----------------------------------------------------------------------------
inline bool WindowApplication::OnMouseClick (int, int, int, int, unsigned int)
{
    // stub for derived classes
    return false;
}
//----------------------------------------------------------------------------
inline bool WindowApplication::OnMotion (int, int, int, unsigned int)
{
    // stub for derived classes
    return false;
}
//----------------------------------------------------------------------------
inline bool WindowApplication::OnPassiveMotion (int, int)
{
    // stub for derived classes
    return false;
}
//----------------------------------------------------------------------------
