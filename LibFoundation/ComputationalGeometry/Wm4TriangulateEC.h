// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4TRIANGULATEEC_H
#define WM4TRIANGULATEEC_H

#include "Wm4FoundationLIB.h"
#include "Wm4Query2.h"
#include "Wm4Vector2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM TriangulateEC
{
public:
    // The input to the constructor is the array of vertices for a simple
    // polygon whose triangulation is required.  The triangulation algorithm
    // is ear-clipping, an O(n^2) method for n input points (iQuantity is n).
    // The triangulation has n-2 triangles, each triangle stored as a triple
    // of indices.  The output array of indices is raiIndex and has 3*(n-2)
    // elements.  This array is dynamically allocated, so you should pass in
    // an unallocated pointer and delete the returned array when you are
    // finished with it.  The input array, if dynamically allocated, should
    // be deleted by the caller.  This class does not assume responsibility
    // for it.
    //
    // You have a choice of speed versus accuracy.  The fastest choice is
    // Query::QT_INT64, but it gives up a lot of precision, scaling the points
    // to [0,2^{20}]^3.  The choice Query::QT_INTEGER gives up less precision,
    // scaling the points to [0,2^{24}]^3.  The choice Query::QT_RATIONAL uses
    // exact arithmetic, but is the slowest choice.  The choice Query::QT_REAL
    // uses floating-point arithmetic, but is not robust in all cases.  The
    // choice Query::QT_FILTERED uses floating-point arithmetic to compute
    // determinants whose signs are of interest.  If the floating-point value
    // is nearly zero, the determinant is recomputed using exact rational
    // arithmetic in order to correctly classify the sign.  The hope is to
    // have an exact result computed faster than with all rational arithmetic.
    // The value fEpsilon is used only for the Query::QT_FILTERED case and
    // should be in [0,1].  If 0, the method defaults to all exact rational
    // arithmetic.  If 1, the method defaults to all floating-point
    // arithmetic.  Generally, if M is the maximum absolute value of a
    // determinant and if d is the current determinant value computed as a
    // floating-point quantity, the recalculation with rational arithmetic
    // occurs when |d| < epsilon*M.

    TriangulateEC (int iQuantity, const Vector2<Real>* akPosition,
        Query::Type eQueryType, Real fEpsilon, int*& raiIndex);

    ~TriangulateEC ();

private:
    bool IsConvex (int i);
    bool IsEar (int i);

    void InsertAfterC (int i);   // insert convex vertex
    void InsertAfterR (int i);   // insert reflex vertesx
    void InsertEndE (int i);     // insert ear at end of list
    void InsertAfterE (int i);   // insert ear after efirst
    void InsertBeforeE (int i);  // insert ear before efirst
    void RemoveV (int i);        // remove vertex
    void RemoveE ();             // remove ear at efirst
    void RemoveR (int i);        // remove reflex vertex

    class WM4_FOUNDATION_ITEM Vertex
    {
    public:
        Vertex ()
        {
            IsConvex = false;
            IsEar = false;
            VPrev = -1;
            VNext = -1;
            SPrev = -1;
            SNext = -1;
            EPrev = -1;
            ENext = -1;
        }

        bool IsConvex, IsEar;
        int VPrev, VNext; // vertex links for polygon
        int SPrev, SNext; // convex/reflex vertex links (disjoint lists)
        int EPrev, ENext; // ear links
    };

    Vertex& V (int i);

    // For robust determinant calculation.
    Query2<Real>* m_pkQuery;

    // Doubly linked lists for storing specially tagged vertices.
    Vertex* m_akVertex;
    int m_iCFirst, m_iCLast;  // linear list of convex vertices
    int m_iRFirst, m_iRLast;  // linear list of reflex vertices
    int m_iEFirst, m_iELast;  // cyclical list of ears
};

}

#endif
