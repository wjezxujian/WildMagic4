// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4CollapseRecord.h"
using namespace Wm4;

//----------------------------------------------------------------------------
CollapseRecord::CollapseRecord (int iVKeep, int iVThrow, int iVQuantity,
    int iTQuantity)
{
    VKeep = iVKeep;
    VThrow = iVThrow;
    VQuantity = iVQuantity;
    TQuantity = iTQuantity;
    IQuantity = 0;
    Index = 0;
}
//----------------------------------------------------------------------------
CollapseRecord::~CollapseRecord ()
{
    WM4_DELETE[] Index;
}
//----------------------------------------------------------------------------
void CollapseRecord::Read (Stream& rkStream)
{
    rkStream.Read(VKeep);
    rkStream.Read(VThrow);
    rkStream.Read(VQuantity);
    rkStream.Read(TQuantity);
    rkStream.Read(IQuantity);
    if (IQuantity > 0)
    {
        Index = WM4_NEW int[IQuantity];
        rkStream.Read(IQuantity,Index);
    }
    else
    {
        Index = 0;
    }
}
//----------------------------------------------------------------------------
void CollapseRecord::Write (Stream& rkStream)
{
    rkStream.Write(VKeep);
    rkStream.Write(VThrow);
    rkStream.Write(VQuantity);
    rkStream.Write(TQuantity);
    rkStream.Write(IQuantity);
    if (IQuantity > 0)
    {
        rkStream.Write(IQuantity,Index);
    }
}
//----------------------------------------------------------------------------
int CollapseRecord::GetDiskUsed () const
{
    return sizeof(VKeep) + sizeof(VThrow) + sizeof(VQuantity) +
        sizeof(TQuantity) + sizeof(IQuantity) + IQuantity*sizeof(Index[0]);
}
//----------------------------------------------------------------------------
