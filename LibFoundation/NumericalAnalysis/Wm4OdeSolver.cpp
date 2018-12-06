// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4FoundationPCH.h"
#include "Wm4OdeSolver.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
OdeSolver<Real>::OdeSolver (int iDim, Real fStep, Function oFunction,
    void* pvData)
{
    m_iDim = iDim;
    m_fStep = fStep;
    m_oFunction = oFunction;
    m_pvData = pvData;
    m_afFValue = WM4_NEW Real[iDim];
}
//----------------------------------------------------------------------------
template <class Real>
OdeSolver<Real>::~OdeSolver ()
{
    WM4_DELETE[] m_afFValue;
}
//----------------------------------------------------------------------------
template <class Real>
Real OdeSolver<Real>::GetStepSize () const
{
    return m_fStep;
}
//----------------------------------------------------------------------------
template <class Real>
void OdeSolver<Real>::SetData (void* pvData)
{
    m_pvData = pvData;
}
//----------------------------------------------------------------------------
template <class Real>
void* OdeSolver<Real>::GetData () const
{
    return m_pvData;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class OdeSolver<float>;

template WM4_FOUNDATION_ITEM
class OdeSolver<double>;
//----------------------------------------------------------------------------
}
