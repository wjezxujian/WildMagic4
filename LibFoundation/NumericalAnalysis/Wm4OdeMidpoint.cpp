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
#include "Wm4OdeMidpoint.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
OdeMidpoint<Real>::OdeMidpoint (int iDim, Real fStep,
    typename OdeSolver<Real>::Function oFunction, void* pvData)
    :
    OdeSolver<Real>(iDim,fStep,oFunction,pvData)
{
    m_fHalfStep = ((Real)0.5)*fStep;
    m_afXTemp = WM4_NEW Real[iDim];
}
//----------------------------------------------------------------------------
template <class Real>
OdeMidpoint<Real>::~OdeMidpoint ()
{
    WM4_DELETE[] m_afXTemp;
}
//----------------------------------------------------------------------------
template <class Real>
void OdeMidpoint<Real>::Update (Real fTIn, Real* afXIn, Real& rfTOut,
    Real* afXOut)
{
    int i;

    // first step
    m_oFunction(fTIn,afXIn,m_pvData,m_afFValue);
    for (i = 0; i < m_iDim; i++)
    {
        m_afXTemp[i] = afXIn[i] + m_fHalfStep*m_afFValue[i];
    }

    // second step
    Real fHalfT = fTIn + m_fHalfStep;
    m_oFunction(fHalfT,m_afXTemp,m_pvData,m_afFValue);
    for (i = 0; i < m_iDim; i++)
    {
        afXOut[i] = afXIn[i] + m_fStep*m_afFValue[i];
    }

    rfTOut = fTIn + m_fStep;
}
//----------------------------------------------------------------------------
template <class Real>
void OdeMidpoint<Real>::SetStepSize (Real fStep)
{
    m_fStep = fStep;
    m_fHalfStep = ((Real)0.5)*fStep;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class OdeMidpoint<float>;

template WM4_FOUNDATION_ITEM
class OdeMidpoint<double>;
//----------------------------------------------------------------------------
}
