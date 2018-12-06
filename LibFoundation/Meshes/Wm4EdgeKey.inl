// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Foundation Library source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4FoundationLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline EdgeKey::EdgeKey (int iV0, int iV1)
{
    if (iV0 < iV1)
    {
        // v0 is minimum
        V[0] = iV0;
        V[1] = iV1;
    }
    else
    {
        // v1 is minimum
        V[0] = iV1;
        V[1] = iV0;
    }
}
//----------------------------------------------------------------------------
inline bool EdgeKey::operator< (const EdgeKey& rkKey) const
{
    if (V[1] < rkKey.V[1])
    {
        return true;
    }

    if (V[1] > rkKey.V[1])
    {
        return false;
    }

    return V[0] < rkKey.V[0];
}
//----------------------------------------------------------------------------
inline EdgeKey::operator size_t () const
{
    return V[0] | (V[1] << 16);
}
//----------------------------------------------------------------------------
