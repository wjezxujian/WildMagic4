// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MESHCURVATURE_H
#define WM4MESHCURVATURE_H

#include "Wm4FoundationLIB.h"
#include "Wm4Matrix3.h"
#include "Wm4Matrix2.h"

namespace Wm4
{

template <class Real>
class WM4_FOUNDATION_ITEM MeshCurvature
{
public:
    // The caller is responsible for deleting the input arrays.
    MeshCurvature (int iVQuantity, const Vector3<Real>* akVertex,
        int iTQuantity, const int* aiIndex);

    virtual ~MeshCurvature ();

    // input values from the constructor
    int GetVQuantity () const;
    const Vector3<Real>* GetVertices () const;
    int GetTQuantity () const;
    const int* GetIndices () const;

    // derived quantites from the input mesh
    const Vector3<Real>* GetNormals () const;
    const Real* GetMinCurvatures () const;
    const Real* GetMaxCurvatures () const;
    const Vector3<Real>* GetMinDirections () const;
    const Vector3<Real>* GetMaxDirections () const;

protected:
    int m_iVQuantity;
    const Vector3<Real>* m_akVertex;
    int m_iTQuantity;
    const int* m_aiIndex;

    Vector3<Real>* m_akNormal;
    Real* m_afMinCurvature;
    Real* m_afMaxCurvature;
    Vector3<Real>* m_akMinDirection;
    Vector3<Real>* m_akMaxDirection;
};

typedef MeshCurvature<float> MeshCurvaturef;
typedef MeshCurvature<double> MeshCurvatured;

}

#endif
