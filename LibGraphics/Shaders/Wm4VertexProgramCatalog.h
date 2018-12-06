// Geometric Tools, Inc.
// http://www.geometrictools.com
// Copyright (c) 1998-2006.  All Rights Reserved
//
// The Wild Magic Version 4 Restricted Libraries source code is supplied
// under the terms of the license agreement
//     http://www.geometrictools.com/License/Wm4RestrictedLicense.pdf
// and may not be copied or disclosed except in accordance with the terms
// of that agreement.

#ifndef WM4VERTEXPROGRAMCATALOG_H
#define WM4VERTEXPROGRAMCATALOG_H

#include "Wm4GraphicsLIB.h"
#include "Wm4Object.h"
#include "Wm4MainMCR.h"

namespace Wm4
{

class VertexProgram;

class WM4_GRAPHICS_ITEM VertexProgramCatalog
{
public:
    VertexProgramCatalog (const std::string& rkName);
    ~VertexProgramCatalog ();

    // For deferred setting of the renderer type and comment character.  This
    // cannot be called until the application layer has created a renderer.
    // The layer does so in WindowApplication::SetRenderer.
    void SetInformation (const std::string& rkRendererType,
        char cCommentChar);

    const std::string& GetName () const;
    bool Insert (VertexProgram* pkProgram);
    bool Remove (VertexProgram* pkProgram);
    VertexProgram* Find (const std::string& rkProgramName);
    bool PrintContents (const std::string& rkFilename) const;

    static void SetActive (VertexProgramCatalog* pkActive);
    static VertexProgramCatalog* GetActive ();

private:
    std::string m_kName;
    std::map<std::string,VertexProgram*> m_kEntry;
    ObjectPtr m_spkDefaultVProgram;
    std::string m_kRendererType;
    char m_cCommentChar;

    static const std::string ms_kNullString;
    static const std::string ms_kDefaultString;
    static VertexProgramCatalog* ms_pkActive;
};

}

#endif
