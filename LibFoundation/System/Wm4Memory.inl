// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2005.  All Rights Reserved
//
// The Wild Magic Library (WM) source code is supplied under the terms of
// the license agreement
//     http://www.geometrictools.com/License/WildMagic4License.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

//----------------------------------------------------------------------------
inline size_t& Memory::MaxAllowedBytes ()
{
    return ms_uiMaxAllowedBytes;
}
//----------------------------------------------------------------------------
inline bool& Memory::TrackSizes ()
{
    return ms_bTrackSizes;
}
//----------------------------------------------------------------------------
inline size_t Memory::GetNumNewCalls ()
{
    return ms_uiNumNewCalls;
}
//----------------------------------------------------------------------------
inline size_t Memory::GetNumDeleteCalls ()
{
    return ms_uiNumDeleteCalls;
}
//----------------------------------------------------------------------------
inline size_t Memory::GetNumBlocks ()
{
    return ms_uiNumBlocks;
}
//----------------------------------------------------------------------------
inline size_t Memory::GetNumBytes ()
{
    return ms_uiNumBytes;
}
//----------------------------------------------------------------------------
inline size_t Memory::GetMaxAllocatedBytes ()
{
    return ms_uiMaxAllocatedBytes;
}
//----------------------------------------------------------------------------
inline size_t Memory::GetMaxBlockSize ()
{
    return ms_uiMaxBlockSize;
}
//----------------------------------------------------------------------------
inline size_t Memory::GetHistogram (int i)
{
    if (0 <= i && i <= 31)
    {
        return ms_auiHistogram[i];
    }

    return 0;
}
//----------------------------------------------------------------------------
inline const Memory::Block* Memory::GetHead ()
{
    return ms_pkHead;
}
//----------------------------------------------------------------------------
inline const Memory::Block* Memory::GetTail ()
{
    return ms_pkTail;
}
//----------------------------------------------------------------------------
