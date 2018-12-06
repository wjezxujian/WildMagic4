// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4BINARY3D_H
#define WM4BINARY3D_H

#include "Wm4FoundationLIB.h"
#include "Wm4Images.h"

namespace Wm4
{

class Binary3D : public ImageInt3D
{
public:
    // Construction and destruction.  Binary3D accepts responsibility for
    // deleting the input data array.
    WM4_FOUNDATION_ITEM Binary3D (int iXBound, int iYBound, int iZBound,
        Eint* atData = 0);
    WM4_FOUNDATION_ITEM Binary3D (const Binary3D& rkImage);
    WM4_FOUNDATION_ITEM Binary3D (const char* acFilename);

    // Compute the connected components of a binary image.  The components in
    // the returned image are labeled with positive integer values.  If the
    // image is identically zero, then the components image is identically
    // zero and the returned quantity is zero.

    WM4_FOUNDATION_ITEM void GetComponents (int& riQuantity,
        ImageInt3D& rkComponents) const;

protected:
    // helper for component labeling
    void AddToAssociative (int i0, int i1, int* aiAssoc) const;
};

}

#endif
