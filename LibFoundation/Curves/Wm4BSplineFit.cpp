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
#include "Wm4BSplineFit.h"
#include "Wm4Math.h"

namespace Wm4
{
//----------------------------------------------------------------------------
template <class Real>
BSplineFit<Real>::BSplineFit (int iDimension, int iSampleQuantity,
    const Real* afSampleData, int iDegree, int iControlQuantity)
    :
    m_kBasis(iControlQuantity,iDegree)
{
    assert(iDimension >= 1);
    assert(1 <= iDegree && iDegree < iControlQuantity);
    assert(iControlQuantity <= iSampleQuantity);

    m_iDimension = iDimension;
    m_iSampleQuantity = iSampleQuantity;
    m_afSampleData = afSampleData;
    m_iDegree = iDegree;
    m_iControlQuantity = iControlQuantity;
    m_afControlData = WM4_NEW Real[m_iDimension*iControlQuantity];

    // Fit the data points with a B-spline curve using a least-squares error
    // metric.  The problem is of the form A^T*A*X = A^T*B.
    BSplineFitBasisd kDBasis(m_iControlQuantity,m_iDegree);
    double dTMultiplier = 1.0/(double)(m_iSampleQuantity - 1);
    double dT;
    int i0, i1, i2, iMin, iMax, j;

    // Construct the matrix A (depends only on the output basis function).
    BandedMatrixd* pkAMat = WM4_NEW BandedMatrixd(m_iControlQuantity,
        m_iDegree+1,m_iDegree+1);

    for (i0 = 0; i0 < m_iControlQuantity; i0++)
    {
        for (i1 = 0; i1 < i0; i1++)
        {
            (*pkAMat)(i0,i1) = (*pkAMat)(i1,i0);
        }

        int i1Max = i0 + m_iDegree;
        if (i1Max >= m_iControlQuantity)
        {
            i1Max = m_iControlQuantity - 1;
        }

        for (i1 = i0; i1 <= i1Max; i1++)
        {
            double dValue = 0.0;
            for (i2 = 0; i2 < m_iSampleQuantity; i2++)
            {
                dT = dTMultiplier*(double)i2;
                kDBasis.Compute(dT,iMin,iMax);
                if (iMin <= i0 && i0 <= iMax && iMin <= i1 && i1 <= iMax)
                {
                    double dB0 = kDBasis.GetValue(i0 - iMin);
                    double dB1 = kDBasis.GetValue(i1 - iMin);
                    dValue += dB0*dB1;
                }
            }
            (*pkAMat)(i0,i1) = dValue;
        }
    }

    // Construct the matrix B.
    double** aadBMat;
    Allocate(m_iSampleQuantity,m_iControlQuantity,aadBMat);
    memset(aadBMat[0],0,m_iControlQuantity*m_iSampleQuantity*sizeof(double));
    for (i0 = 0; i0 < m_iControlQuantity; i0++)
    {
        for (i1 = 0; i1 < m_iSampleQuantity; i1++)
        {
            dT = dTMultiplier*(double)i1;
            kDBasis.Compute(dT,iMin,iMax);
            if (iMin <= i0 && i0 <= iMax)
            {
                aadBMat[i0][i1] = kDBasis.GetValue(i0 - iMin);
            }
        }
    }

    // Construct the control points for the least-squares curve.
    double* adControlData = WM4_NEW double[m_iDimension*m_iControlQuantity];
    memset(adControlData,0,m_iDimension*m_iControlQuantity*sizeof(double));
    double* pdBaseTarget = adControlData;
    for (i0 = 0; i0 < m_iControlQuantity; i0++)
    {
        const Real* pfSource = m_afSampleData;
        double* adTarget = pdBaseTarget;
        for (i1 = 0; i1 < m_iSampleQuantity; i1++)
        {
            double dBValue = aadBMat[i0][i1];
            for (j = 0; j < m_iDimension; j++)
            {
                adTarget[j] += dBValue*(double)(*pfSource++);
            }
        }
        pdBaseTarget += m_iDimension;
    }

    // Solve A^T*A*ControlData = A^T*B*SampleData.
    bool bSolved = CholeskyFactor(*pkAMat);
    assert(bSolved);
    bSolved = SolveLower(*pkAMat,adControlData);
    assert(bSolved);
    bSolved = SolveUpper(*pkAMat,adControlData);
    assert(bSolved);

    // Set the B-spline control points.
    Real* pfTarget = m_afControlData;
    const double* pdSource = adControlData;
    for (i0 = 0; i0 < m_iDimension*m_iControlQuantity; i0++)
    {
        *pfTarget++ = (Real)(*pdSource++);
    }

    // Set the first and last output control points to match the first and
    // last input samples.  This supports the application of fitting keyframe
    // data with B-spline curves.  The user expects that the curve passes
    // through the first and last positions in order to support matching two
    // consecutive keyframe sequences.
    Real* pfCEnd0 = m_afControlData;
    const Real* pfSEnd0 = m_afSampleData;
    Real* pfCEnd1 = &m_afControlData[m_iDimension*(m_iControlQuantity-1)];
    const Real* pfSEnd1 = &m_afSampleData[m_iDimension*(m_iSampleQuantity-1)];
    for (j = 0; j < m_iDimension; j++)
    {
        *pfCEnd0++ = *pfSEnd0++;
        *pfCEnd1++ = *pfSEnd1++;
    }

    WM4_DELETE[] adControlData;
    Deallocate(aadBMat);
    WM4_DELETE pkAMat;
}
//----------------------------------------------------------------------------
template <class Real>
BSplineFit<Real>::~BSplineFit ()
{
    WM4_DELETE[] m_afControlData;
}
//----------------------------------------------------------------------------
template <class Real>
int BSplineFit<Real>::GetDimension () const
{
    return m_iDimension;
}
//----------------------------------------------------------------------------
template <class Real>
int BSplineFit<Real>::GetSampleQuantity () const
{
    return m_iSampleQuantity;
}
//----------------------------------------------------------------------------
template <class Real>
const Real* BSplineFit<Real>::GetSampleData () const
{
    return m_afSampleData;
}
//----------------------------------------------------------------------------
template <class Real>
int BSplineFit<Real>::GetDegree () const
{
    return m_iDegree;
}
//----------------------------------------------------------------------------
template <class Real>
int BSplineFit<Real>::GetControlQuantity () const
{
    return m_iControlQuantity;
}
//----------------------------------------------------------------------------
template <class Real>
const Real* BSplineFit<Real>::GetControlData () const
{
    return m_afControlData;
}
//----------------------------------------------------------------------------
template <class Real>
const BSplineFitBasis<Real>& BSplineFit<Real>::GetBasis () const
{
    return m_kBasis;
}
//----------------------------------------------------------------------------
template <class Real>
void BSplineFit<Real>::GetPosition (Real fT, Real* afPosition) const
{
    assert(afPosition);

    int iMin, iMax;
    m_kBasis.Compute(fT,iMin,iMax);

    Real* pfSource = &m_afControlData[m_iDimension*iMin];
    Real fBasisValue = m_kBasis.GetValue(0);
    int j;
    for (j = 0; j < m_iDimension; j++)
    {
        afPosition[j] = fBasisValue*(*pfSource++);
    }

    for (int i = iMin+1, iIndex = 1; i <= iMax; i++, iIndex++)
    {
        fBasisValue = m_kBasis.GetValue(iIndex);
        for (j = 0; j < m_iDimension; j++)
        {
            afPosition[j] += fBasisValue*(*pfSource++);
        }
    }
}
//----------------------------------------------------------------------------
template <class Real>
bool BSplineFit<Real>::CholeskyFactor (BandedMatrixd& rkMatrix) const
{
    const int iSize = rkMatrix.GetSize(), iSizeM1 = iSize - 1;
    const int iBands = rkMatrix.GetLBands();  // == GetUBands()

    int k, kMax;
    for (int i = 0; i < iSize; i++)
    {
        int jMin = i - iBands;
        if (jMin < 0)
        {
            jMin = 0;
        }

        int j;
        for (j = jMin; j < i; j++)
        {
            kMax = j + iBands;
            if (kMax > iSizeM1)
            {
                kMax = iSizeM1;
            }

            for (k = i; k <= kMax; k++)
            {
                rkMatrix(k,i) -= rkMatrix(i,j)*rkMatrix(k,j);
            }
        }

        kMax = j + iBands;
        if (kMax > iSizeM1)
        {
            kMax = iSizeM1;
        }

        for (k = 0; k < i; k++)
        {
            rkMatrix(k,i) = rkMatrix(i,k);
        }

        double dDiagonal = rkMatrix(i,i);
        if (dDiagonal <= 0.0)
        {
            return false;
        }
        double dInvSqrt = Mathd::InvSqrt(dDiagonal);
        for (k = i; k <= kMax; k++)
        {
            rkMatrix(k,i) *= dInvSqrt;
        }
    }

    return true;
}
//----------------------------------------------------------------------------
template <class Real>
bool BSplineFit<Real>::SolveLower (BandedMatrixd& rkMatrix,
    double* adControlData) const
{
    const int iSize = rkMatrix.GetSize();
    double* pdBaseTarget = adControlData;
    for (int iRow = 0; iRow < iSize; iRow++)
    {
        if (Mathd::FAbs(rkMatrix(iRow,iRow)) < Mathd::ZERO_TOLERANCE)
        {
            return false;
        }

        const double* pdBaseSource = adControlData;
        double* adTarget = pdBaseTarget;
        int j;
        for (int iCol = 0; iCol < iRow; iCol++)
        {
            const double* pdSource = pdBaseSource;
            double dMatValue = rkMatrix(iRow,iCol);
            for (j = 0; j < m_iDimension; j++)
            {
                adTarget[j] -= dMatValue*(*pdSource++);
            }
            pdBaseSource += m_iDimension;
        }

        double dInverse = 1.0/rkMatrix(iRow,iRow);
        for (j = 0; j < m_iDimension; j++)
        {
            adTarget[j] *= dInverse;
        }
        pdBaseTarget += m_iDimension;
    }

    return true;
}
//----------------------------------------------------------------------------
template <class Real>
bool BSplineFit<Real>::SolveUpper (BandedMatrixd& rkMatrix,
    double* adControlData) const
{
    const int iSize = rkMatrix.GetSize();
    double* pdBaseTarget = &adControlData[m_iDimension*(iSize-1)];
    for (int iRow = iSize - 1; iRow >= 0; iRow--)
    {
        if (Mathd::FAbs(rkMatrix(iRow,iRow)) < Mathd::ZERO_TOLERANCE)
        {
            return false;
        }

        const double* pdBaseSource = &adControlData[m_iDimension*(iRow+1)];
        double* adTarget = pdBaseTarget;
        int j;
        for (int iCol = iRow+1; iCol < iSize; iCol++)
        {
            const double* pdSource = pdBaseSource;
            double dMatValue = rkMatrix(iRow,iCol);
            for (j = 0; j < m_iDimension; j++)
            {
                adTarget[j] -= dMatValue*(*pdSource++);
            }
            pdBaseSource += m_iDimension;
        }

        double dInverse = 1.0/rkMatrix(iRow,iRow);
        for (j = 0; j < m_iDimension; j++)
        {
            adTarget[j] *= dInverse;
        }
        pdBaseTarget -= m_iDimension;
    }

    return true;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// explicit instantiation
//----------------------------------------------------------------------------
template WM4_FOUNDATION_ITEM
class BSplineFit<float>;

template WM4_FOUNDATION_ITEM
class BSplineFit<double>;
//----------------------------------------------------------------------------
}
