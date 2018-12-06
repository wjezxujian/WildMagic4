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
inline void SwitchNode::SetActiveChild (int iActiveChild)
{
    assert(iActiveChild == SN_INVALID_CHILD || iActiveChild < GetQuantity());
    m_iActiveChild = iActiveChild;
}
//----------------------------------------------------------------------------
inline int SwitchNode::GetActiveChild () const
{
    return m_iActiveChild;
}
//----------------------------------------------------------------------------
inline void SwitchNode::DisableAllChildren ()
{
    m_iActiveChild = SN_INVALID_CHILD;
}
//----------------------------------------------------------------------------
