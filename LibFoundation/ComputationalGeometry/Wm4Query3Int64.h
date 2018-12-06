// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4QUERY3INT64_H
#define WM4QUERY3INT64_H

#include "Wm4FoundationLIB.h"
#include "Wm4Query3.h"

namespace Wm4
{

template <class Real>
class Query3Int64 : public Query3<Real>
{
public:
    // The components of the input vertices are truncated to 64-bit integer
    // values, so you should guarantee that the vertices are sufficiently
    // large to give a good distribution of numbers.
    Query3Int64 (int iVQuantity, const Vector3<Real>* akVertex);

    // run-time type information
    virtual Query::Type GetType () const;

    // Queries about the relation of a point to various geometric objects.

    virtual int ToPlane (const Vector3<Real>& rkP, int iV0, int iV1, int iV2)
        const;

    virtual int ToCircumsphere (const Vector3<Real>& rkP, int iV0, int iV1,
        int iV2, int iV3) const;

private:
    using Query3<Real>::m_akVertex;

    static Integer64 Dot (Integer64 iX0, Integer64 iY0, Integer64 iZ0,
        Integer64 iX1, Integer64 iY1, Integer64 iZ1);

    static Integer64 Det3 (Integer64 iX0, Integer64 iY0, Integer64 iZ0,
        Integer64 iX1, Integer64 iY1, Integer64 iZ1, Integer64 iX2,
        Integer64 iY2, Integer64 iZ2);

    static Integer64 Det4 (Integer64 iX0, Integer64 iY0, Integer64 iZ0,
        Integer64 iW0, Integer64 iX1, Integer64 iY1, Integer64 iZ1,
        Integer64 iW1, Integer64 iX2, Integer64 iY2, Integer64 iZ2,
        Integer64 iW2, Integer64 iX3, Integer64 iY3, Integer64 iZ3,
        Integer64 iW3);
};

#include "Wm4Query3Int64.inl"

typedef Query3Int64<float> Query3Int64f;
typedef Query3Int64<double> Query3Int64d;

}

#endif
