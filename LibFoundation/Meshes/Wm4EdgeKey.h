// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4EDGEKEY_H
#define WM4EDGEKEY_H

#include "Wm4FoundationLIB.h"
#include "Wm4System.h"

namespace Wm4
{

class WM4_FOUNDATION_ITEM EdgeKey
{
public:
    EdgeKey (int iV0 = -1, int iV1 = -1);
    bool operator< (const EdgeKey& rkKey) const;
    operator size_t () const;
    int V[2];
};

#include "Wm4EdgeKey.inl"

}

#endif
