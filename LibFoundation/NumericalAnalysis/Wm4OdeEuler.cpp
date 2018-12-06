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
#include "Wm4OdeEuler.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
OdeEuler<Real>::OdeEuler (int iDim, Real fStep,
    typename OdeSolver<Real>::Function oFunction, void* pvData)
    :
    OdeSolver<Real>(iDim,fStep,oFunction,pvData)
{
}
//----------------------------------------------------------------------------
template <class Real>
OdeEuler<Real>::~OdeEuler ()
{
}
//----------------------------------------------------------------------------
template <class Real>
void OdeEuler<Real>::Update (Real fTIn, Real* afXIn, Real& rfTOut,
    Real* afXOut)
{
    m_oFunction(fTIn,afXIn,m_pvData,m_afFValue);
    for (int i = 0; i < m_iDim; i++)
    {
        afXOut[i] = afXIn[i] + m_fStep*m_afFValue[i];
    }

    rfTOut = fTIn + m_fStep;
}
//----------------------------------------------------------------------------
template <class Real>
void OdeEuler<Real>::SetStepSize (Real fStep)
{
    m_fStep = fStep;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class OdeEuler<float>;

template WM4_FOUNDATION_ITEM
class OdeEuler<double>;
//----------------------------------------------------------------------------
}
