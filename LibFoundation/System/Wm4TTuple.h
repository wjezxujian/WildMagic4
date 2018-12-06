// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TTUPLE_H
#define WM4TTUPLE_H

#include "Wm4FoundationLIB.h"
#include "Wm4System.h"

// The class TYPE is either native data or is class data that has the
// following member functions:
//   TYPE::TYPE ()
//   TYPE::TYPE (const TYPE&);
//   TYPE& TYPE::operator= (const TYPE&)

namespace Wm4
{

template <int DIMENSION, class TYPE>
class TTuple
{
public:
    // Construction and destruction.  The default constructor does not
    // initialize the tuple elements for native elements.  The tuple elements
    // are initialized for class data whenever TYPE initializes during its
    // default construction.
    TTuple ();
    TTuple (const TTuple& rkT);
    ~TTuple ();

    // coordinate access
    operator const TYPE* () const;
    operator TYPE* ();
    TYPE operator[] (int i) const;
    TYPE& operator[] (int i);

    // assignment
    TTuple& operator= (const TTuple& rkT);

    // Comparison.  The inequalities make the comparisons using memcmp, thus
    // treating the tuple as an array of unsigned bytes.
    bool operator== (const TTuple& rkT) const;
    bool operator!= (const TTuple& rkT) const;
    bool operator<  (const TTuple& rkT) const;
    bool operator<= (const TTuple& rkT) const;
    bool operator>  (const TTuple& rkT) const;
    bool operator>= (const TTuple& rkT) const;

private:
    TYPE m_atTuple[DIMENSION];
};

#include "Wm4TTuple.inl"

}

#endif
