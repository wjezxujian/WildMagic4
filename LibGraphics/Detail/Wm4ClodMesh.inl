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
inline int ClodMesh::GetRecordQuantity () const
{
    return m_iRecordQuantity;
}
//----------------------------------------------------------------------------
inline int& ClodMesh::TargetRecord ()
{
    return m_iTargetRecord;
}
//----------------------------------------------------------------------------
inline int ClodMesh::GetAutomatedTargetRecord ()
{
    return m_iTargetRecord;
}
//----------------------------------------------------------------------------
