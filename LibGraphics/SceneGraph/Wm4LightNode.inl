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
inline Light* LightNode::GetLight ()
{
    return m_spkLight;
}
//----------------------------------------------------------------------------
inline const Light* LightNode::GetLight () const
{
    return m_spkLight;
}
//----------------------------------------------------------------------------
