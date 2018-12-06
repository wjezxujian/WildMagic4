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
#include "Wm4VertexProgramCatalog.h"
#include "Wm4VertexProgram.h"
using namespace Wm4;

const std::string VertexProgramCatalog::ms_kNullString("");
const std::string VertexProgramCatalog::ms_kDefaultString("Default");
VertexProgramCatalog* VertexProgramCatalog::ms_pkActive = 0;

//----------------------------------------------------------------------------
VertexProgramCatalog::VertexProgramCatalog (const std::string& rkName)
    :
    m_kName(rkName),
    m_kRendererType(ms_kNullString)
{
    m_cCommentChar = 0;
}
//----------------------------------------------------------------------------
VertexProgramCatalog::~VertexProgramCatalog ()
{
}
//----------------------------------------------------------------------------
void VertexProgramCatalog::SetInformation (const std::string& rkRendererType,
    char cCommentChar)
{
    m_kRendererType = rkRendererType;
    m_cCommentChar = cCommentChar;

    if (m_cCommentChar)
    {
        // Create the default shader, which sets every pixel to magenta.  This
        // is used when your shader cannot be found.  The color should catch
        // your attention.
        m_spkDefaultVProgram = VertexProgram::Load(ms_kDefaultString,
            m_kRendererType,m_cCommentChar);
        assert(m_spkDefaultVProgram);
    }
    else
    {
        // Release the default shader.
        m_spkDefaultVProgram = 0;
    }
}
//----------------------------------------------------------------------------
const std::string& VertexProgramCatalog::GetName () const
{
    return m_kName;
}
//----------------------------------------------------------------------------
bool VertexProgramCatalog::Insert (VertexProgram* pkProgram)
{
    if (!pkProgram)
    {
        assert(false);
        return false;
    }

    std::string kProgramName(pkProgram->GetName());
    if (kProgramName == ms_kNullString
    ||  kProgramName == ms_kDefaultString
    ||  pkProgram == m_spkDefaultVProgram)
    {
        return false;
    }

    // Attempt to find the program in the catalog.
    std::map<std::string,VertexProgram*>::iterator pkIter =
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
bool VertexProgramCatalog::Remove (VertexProgram* pkProgram)
{
    if (!pkProgram)
    {
        assert(false);
        return false;
    }

    std::string kProgramName(pkProgram->GetName());
    if (kProgramName == ms_kNullString
    ||  kProgramName == ms_kDefaultString
    ||  pkProgram == m_spkDefaultVProgram)
    {
        return false;
    }

    // Attempt to find the program in the catalog.
    std::map<std::string,VertexProgram*>::iterator pkIter =
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
VertexProgram* VertexProgramCatalog::Find (const std::string& rkProgramName)
{
    if (rkProgramName == ms_kNullString
    ||  rkProgramName == ms_kDefaultString)
    {
        return StaticCast<VertexProgram>(m_spkDefaultVProgram);
    }

    // Attempt to find the program in the catalog.
    std::map<std::string,VertexProgram*>::iterator pkIter =
        m_kEntry.find(rkProgramName);
    if (pkIter != m_kEntry.end())
    {
        // The program exists in the catalog, so return it.
        return pkIter->second;
    }

    // Attempt to load the program from disk.  On a successful load, the
    // (name,program) pair was automatically inserted into m_kEntry, so
    // there is no need to insert it again explicitly.
    assert(m_cCommentChar);
    VertexProgram* pkProgram = VertexProgram::Load(rkProgramName,
        m_kRendererType,m_cCommentChar);
    if (pkProgram)
    {
        // The program exists on disk and is already in the catalog.  The
        // (name,program) pair was automatically inserted into m_kEntry by
        // VertexProgram::Load, so there is no need to insert it again
        // explicitly.
        return pkProgram;
    }

    // The program does not exist.  Use the default program.
    return StaticCast<VertexProgram>(m_spkDefaultVProgram);
}
//----------------------------------------------------------------------------
bool VertexProgramCatalog::PrintContents (const std::string& rkFilename) const
{
    const char* acDecorated = System::GetPath(rkFilename.c_str(),
        System::SM_WRITE);

    if (acDecorated)
    {
        std::ofstream kOStr(acDecorated);
        assert(kOStr);

        std::map<std::string,VertexProgram*>::const_iterator pkIter;
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
void VertexProgramCatalog::SetActive (VertexProgramCatalog* pkActive)
{
    ms_pkActive = pkActive;
}
//----------------------------------------------------------------------------
VertexProgramCatalog* VertexProgramCatalog::GetActive ()
{
    return ms_pkActive;
}
//----------------------------------------------------------------------------
