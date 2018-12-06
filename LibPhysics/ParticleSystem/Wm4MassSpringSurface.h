// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4MASSSPRINGSURFACE_H
#define WM4MASSSPRINGSURFACE_H

#include "Wm4PhysicsLIB.h"
#include "Wm4ParticleSystem.h"

namespace Wm4
{

template <class Real, class TVector>
class WM4_PHYSICS_ITEM MassSpringSurface : public ParticleSystem<Real,TVector>
{
public:
    // Construction and destruction.  This class represents an RxC array of
    // masses lying on a surface and connected by an array of springs.  The
    // masses are indexed by mass[r][c] for 0 <= r < R and 0 <= c < C.  The
    // mass at interior position X[r][c] is connected by springs to the
    // masses at positions X[r-1][c], X[r+1][c], X[r][c-1], and X[r][c+1].
    // Boundary masses have springs connecting them to the obvious neighbors
    // ("edge" mass has 3 neighbors, "corner" mass has 2 neighbors).  The
    // masses are arranged in row-major order:  position[c+C*r] = X[r][c]
    // for 0 <= r < R and 0 <= c < C.  The other arrays are stored similarly.
    MassSpringSurface (int iRows, int iCols, Real fStep);
    virtual ~MassSpringSurface ();

    int GetRows () const;
    int GetCols () const;
    void SetMass (int iRow, int iCol, Real fMass);
    Real GetMass (int iRow, int iCol) const;
    TVector** Positions2D () const;
    TVector& Position (int iRow, int iCol);
    TVector** Velocities2D () const;
    TVector& Velocity (int iRow, int iCol);

    // The interior mass at (r,c) has springs to the left, right, bottom, and
    // top.  Edge masses have only three neighbors and corner masses have only
    // two neighbors.  The mass at (r,c) provides access to the springs
    // connecting to locations (r,c+1) and (r+1,c).  Edge and corner masses
    // provide access to only a subset of these.  The caller is responsible
    // for ensuring the validity of the (r,c) inputs.
    Real& ConstantR (int iRow, int iCol);  // spring to (r+1,c)
    Real& LengthR (int iRow, int iCol);    // spring to (r+1,c)
    Real& ConstantC (int iRow, int iCol);  // spring to (r,c+1)
    Real& LengthC (int iRow, int iCol);    // spring to (r,c+1)

    // Callback for acceleration (ODE solver uses x" = F/m) applied to
    // particle i.  The positions and velocities are not necessarily
    // m_akPosition and m_akVelocity since the ODE solver evaluates the
    // impulse function at intermediate positions.
    virtual TVector Acceleration (int i, Real fTime,
        const TVector* akPosition, const TVector* akVelocity);

    // The default external force is zero.  Derive a class from this one to
    // provide nonzero external forces such as gravity, wind, friction,
    // and so on.  This function is called by Acceleration(...) to append the
    // acceleration F/m generated by the external force F.
    virtual TVector ExternalAcceleration (int i, Real fTime,
        const TVector* akPosition, const TVector* akVelocity);

protected:
    using ParticleSystem<Real,TVector>::m_afInvMass;
    using ParticleSystem<Real,TVector>::m_akPosition;
    using ParticleSystem<Real,TVector>::m_akVelocity;

    int GetIndex (int iRow, int iCol) const;
    void GetCoordinates (int i, int& riRow, int& riCol) const;

    int m_iRows;              // R
    int m_iCols;              // C
    TVector** m_aakPosition;  // R-by-C
    TVector** m_aakVelocity;  // R-by-C

    int m_iRowsM1;            // R-1
    int m_iColsM1;            // C-1
    Real** m_aafConstantR;    // (R-1)-by-C
    Real** m_aafLengthR;      // (R-1)-by-C
    Real** m_aafConstantC;    // R-by-(C-1)
    Real** m_aafLengthC;      // R-by-(C-1)
};

typedef MassSpringSurface<float,Vector2f> MassSpringSurface2f;
typedef MassSpringSurface<double,Vector2d> MassSpringSurface2d;
typedef MassSpringSurface<float,Vector3f> MassSpringSurface3f;
typedef MassSpringSurface<double,Vector3d> MassSpringSurface3d;

}

#endif
