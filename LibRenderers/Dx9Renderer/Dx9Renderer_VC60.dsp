# Microsoft Developer Studio Project File - Name="Dx9Renderer_VC60" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Dx9Renderer_VC60 - Win32 NoPCH
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Dx9Renderer_VC60.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Dx9Renderer_VC60.mak" CFG="Dx9Renderer_VC60 - Win32 NoPCH"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Dx9Renderer_VC60 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "Dx9Renderer_VC60 - Win32 Debug Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "Dx9Renderer_VC60 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Dx9Renderer_VC60 - Win32 Release Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "Dx9Renderer_VC60 - Win32 NoPCH" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug\VC60"
# PROP BASE Intermediate_Dir "Debug\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug\VC60"
# PROP Intermediate_Dir "Debug\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\SDK\Include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4Dx9RendererPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\SDK\Library\Debug\Wm4Dx9Renderer60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 Debug Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMemory\VC60"
# PROP BASE Intermediate_Dir "DebugMemory\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMemory\VC60"
# PROP Intermediate_Dir "DebugMemory\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "..\..\Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\SDK\Include" /D "_DEBUG" /D "WM4_MEMORY_MANAGER" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4Dx9RendererPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\Library\Debug\Wm4Dx9Renderer60d.lib"
# ADD LIB32 /nologo /out:"..\..\SDK\Library\DebugMemory\Wm4Dx9Renderer60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release\VC60"
# PROP BASE Intermediate_Dir "Release\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release\VC60"
# PROP Intermediate_Dir "Release\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\..\SDK\Include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4Dx9RendererPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\SDK\Library\Release\Wm4Dx9Renderer60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 Release Memory"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMemory\VC60"
# PROP BASE Intermediate_Dir "ReleaseMemory\VC60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMemory\VC60"
# PROP Intermediate_Dir "ReleaseMemory\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "..\..\Include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "..\..\SDK\Include" /D "NDEBUG" /D "WM4_MEMORY_MANAGER" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4Dx9RendererPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\Library\Release\Wm4Dx9Renderer60.lib"
# ADD LIB32 /nologo /out:"..\..\SDK\Library\ReleaseMemory\Wm4Dx9Renderer60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 NoPCH"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Dx9Renderer_VC60___Win32_NoPCH"
# PROP BASE Intermediate_Dir "Dx9Renderer_VC60___Win32_NoPCH"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NoPCH\VC60"
# PROP Intermediate_Dir "NoPCH\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\SDK\Include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4Dx9RendererPCH.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\..\SDK\Include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\SDK\Library\Debug\Wm4Dx9Renderer60d.lib"
# ADD LIB32 /nologo /out:"..\..\SDK\Library\NoPCH\Wm4Dx9Renderer60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy *.h ..\..\SDK\Include
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "Dx9Renderer_VC60 - Win32 Debug"
# Name "Dx9Renderer_VC60 - Win32 Debug Memory"
# Name "Dx9Renderer_VC60 - Win32 Release"
# Name "Dx9Renderer_VC60 - Win32 Release Memory"
# Name "Dx9Renderer_VC60 - Win32 NoPCH"
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Wm4Dx9FrameBuffer.h
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9Renderer.h
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9Resources.h
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9Utility.h
# End Source File
# End Group
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Wm4Dx9AlphaState.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9CullState.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9DrawBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9DrawElements.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9DrawText.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9FrameBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9PolygonOffsetState.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9Renderer.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9ResourcesED.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9ResourcesLR.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9StencilState.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9Transformation.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9WireframeState.cpp
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9ZBufferState.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\Wm4Dx9RendererLIB.h
# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9RendererPCH.cpp

!IF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 Debug"

# ADD CPP /Yc"Wm4Dx9RendererPCH.h"

!ELSEIF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 Debug Memory"

# ADD CPP /Yc"Wm4Dx9RendererPCH.h"

!ELSEIF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 Release"

# ADD CPP /Yc"Wm4Dx9RendererPCH.h"

!ELSEIF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 Release Memory"

# ADD CPP /Yc"Wm4Dx9RendererPCH.h"

!ELSEIF  "$(CFG)" == "Dx9Renderer_VC60 - Win32 NoPCH"

# ADD BASE CPP /Yc"Wm4Dx9RendererPCH.h"
# SUBTRACT CPP /YX /Yc

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Wm4Dx9RendererPCH.h
# End Source File
# End Target
# End Project

