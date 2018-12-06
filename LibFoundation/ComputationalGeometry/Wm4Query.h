// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4QUERY_H
#define WM4QUERY_H

#include "Wm4FoundationLIB.h"

namespace Wm4
{

class Query
{
public:
    // abstract base class
    virtual ~Query ();

    // run-time type information
    enum Type
    {
        QT_INT64,
        QT_INTEGER,
        QT_RATIONAL,
        QT_REAL,
        QT_FILTERED
    };

    virtual Type GetType () const = 0;

protected:
    Query ();
};

#include "Wm4Query.inl"

}

#endif
