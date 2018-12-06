// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#include "Wm4GraphicsPCH.h"
#include "Wm4PixelProgramCatalog.h"
#include "Wm4PixelProgram.h"
using namespace Wm4;

const std::string PixelProgramCatalog::ms_kNullString("");
const std::string PixelProgramCatalog::ms_kDefaultString("Default");
PixelProgramCatalog* PixelProgramCatalog::ms_pkActive = 0;

//----------------------------------------------------------------------------
PixelProgramCatalog::PixelProgramCatalog (const std::string& rkName)
    :
    m_kName(rkName),
    m_kRendererType(ms_kNullString)
{
    m_cCommentChar = 0;
}
//----------------------------------------------------------------------------
PixelProgramCatalog::~PixelProgramCatalog ()
{
}
//----------------------------------------------------------------------------
void PixelProgramCatalog::SetInformation (const std::string& rkRendererType,
    char cCommentChar)
{
    m_kRendererType = rkRendererType;
    m_cCommentChar = cCommentChar;

    if (m_cCommentChar)
    {
        // Create the default shader, which sets every pixel to magenta.  This
        // is used when your shader cannot be found.  The color should catch
        // your attention.
        m_spkDefaultPProgram = PixelProgram::Load(ms_kDefaultString,
            m_kRendererType,m_cCommentChar);
        assert(m_spkDefaultPProgram);
    }
    else
    {
        // Release the default shader.
        m_spkDefaultPProgram = 0;
    }
}
//----------------------------------------------------------------------------
const std::string& PixelProgramCatalog::GetName () const
{
    return m_kName;
}
//----------------------------------------------------------------------------
bool PixelProgramCatalog::Insert (PixelProgram* pkProgram)
{
    if (!pkProgram)
    {
        assert(false);
        return false;
    }

    std::string kProgramName(pkProgram->GetName());
    if (kProgramName == ms_kNullString
    ||  kProgramName == ms_kDefaultString
    ||  pkProgram == m_spkDefaultPProgram)
    {
        return false;
    }

    // Attempt to find the program in the catalog.
    std::map<std::string,PixelProgram*>::iterator pkIter =
        m_kEntry.find(kProgramName);
    if (pkIter != m_kEntry.end())
    {
        // The program already exists in the catalog.
        return true;
    }

    // The program does not exist in the catalog, so insert it.
    m_kEntry.insert(std::make_pair(kProgramName,pkProgram));
    return true;
}
//----------------------------------------------------------------------------
bool PixelProgramCatalog::Remove (PixelProgram* pkProgram)
{
    if (!pkProgram)
    {
        assert(false);
        return false;
    }

    std::string kProgramName(pkProgram->GetName());
    if (kProgramName == ms_kNullString
    ||  kProgramName == ms_kDefaultString
    ||  pkProgram == m_spkDefaultPProgram)
    {
        return false;
    }

    // Attempt to find the program in the catalog.
    std::map<std::string,PixelProgram*>::iterator pkIter =
        m_kEntry.find(kProgramName);
    if (pkIter == m_kEntry.end())
    {
        // The program does not exist in the catalog.
        return false;
    }

    // The program exists in the catalog.
    m_kEntry.erase(pkIter);
    return true;
}
//----------------------------------------------------------------------------
PixelProgram* PixelProgramCatalog::Find (const std::string& rkProgramName)
{
    if (rkProgramName == ms_kNullString
    ||  rkProgramName == ms_kDefaultString)
    {
        return StaticCast<PixelProgram>(m_spkDefaultPProgram);
    }

    // Attempt to find the program in the catalog.
    std::map<std::string,PixelProgram*>::iterator pkIter =
        m_kEntry.find(rkProgramName);
    if (pkIter != m_kEntry.end())
    {
        // The program exists in the catalog, so return it.
        return pkIter->second;
    }

    // Attempt to load the program from disk.
    assert(m_cCommentChar);
    PixelProgram* pkProgram = PixelProgram::Load(rkProgramName,
        m_kRendererType,m_cCommentChar);
    if (pkProgram)
    {
        // The program exists on disk and is already in the catalog.  The
        // (name,program) pair was automatically inserted into m_kEntry by
        // PixelProgram::Load, so there is no need to insert it again
        // explicitly.
        return pkProgram;
    }

    // The program does not exist.  Use the default program.
    return StaticCast<PixelProgram>(m_spkDefaultPProgram);
}
//----------------------------------------------------------------------------
bool PixelProgramCatalog::PrintContents (const std::string& rkFilename) const
{
    const char* acDecorated = System::GetPath(rkFilename.c_str(),
        System::SM_WRITE);

    if (acDecorated)
    {
        std::ofstream kOStr(acDecorated);
        assert(kOStr);

        std::map<std::string,PixelProgram*>::const_iterator pkIter;
        for (pkIter = m_kEntry.begin(); pkIter != m_kEntry.end(); pkIter++)
        {
            // TO DO.  Print out information about the program?
            kOStr << pkIter->first << std::endl;
            kOStr << std::endl;
        }
        kOStr.close();
        return true;
    }

    return false;
}
//----------------------------------------------------------------------------
void PixelProgramCatalog::SetActive (PixelProgramCatalog* pkActive)
{
    ms_pkActive = pkActive;
}
//----------------------------------------------------------------------------
PixelProgramCatalog* PixelProgramCatalog::GetActive ()
{
    return ms_pkActive;
}
//----------------------------------------------------------------------------
