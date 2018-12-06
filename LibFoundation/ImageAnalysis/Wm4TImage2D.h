// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TIMAGE2D_H
#define WM4TIMAGE2D_H

#include "Wm4FoundationLIB.h"
#include "Wm4TImage.h"

namespace Wm4
{

template <class T>
class TImage2D : public TImage<T>
{
public:
    // Construction and destruction.  TImage2D accepts responsibility for
    // deleting the input data array.
    TImage2D (int iXBound, int iYBound, T* atData = 0);
    TImage2D (const TImage2D& rkImage);
    TImage2D (const char* acFilename);

    // data access
    T& operator() (int iX, int iY) const;

    // conversion between 2D coordinates and 1D indexing
    int GetIndex (int iX, int iY) const;
    void GetCoordinates (int iIndex, int& riX, int& riY) const;

    // assignment
    TImage2D& operator= (const TImage2D& rkImage);
    TImage2D& operator= (T tValue);

protected:
    using TImage<T>::SetData;
    using TImage<T>::m_atData;
};

#include "Wm4TImage2D.inl"

}

#endif
