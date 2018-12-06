# Microsoft Developer Studio Project File - Name="LibPhysics_VC60" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=LibPhysics_VC60 - Win32 NoPCH
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LibPhysics_VC60.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LibPhysics_VC60.mak" CFG="LibPhysics_VC60 - Win32 NoPCH"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LibPhysics_VC60 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibPhysics_VC60 - Win32 Debug Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "LibPhysics_VC60 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibPhysics_VC60 - Win32 Release Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "LibPhysics_VC60 - Win32 NoPCH" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LibPhysics_VC60 - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Intersection" /I "LCPSolver" /I "ParticleSystem" /I "RigidBody" /I "..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4PhysicsPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\SDK\Library\Debug\Wm4Physics60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy /y Intersection\*.h ..\SDK\Include	copy /y LCPSolver\*.h ..\SDK\Include	copy /y ParticleSystem\*.h ..\SDK\Include	copy /y RigidBody\*.h ..\SDK\Include	copy /y *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibPhysics_VC60 - Win32 Debug Memory"

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
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "Approximation" /I "Collision" /I "Containment" /I "Controllers" /I "Curves" /I "Detail" /I "Distance" /I "Effects" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Math" /I "Meshes" /I "Miscellaneous" /I "Numerics" /I "ObjectSystem" /I "Physics" /I "RationalArithmetic" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "System" /I "Terrain" /I "Tessellation" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Intersection" /I "LCPSolver" /I "ParticleSystem" /I "RigidBody" /I "..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /D "WM4_MEMORY_MANAGER" /Yu"Wm4PhysicsPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Debug\Wm3Physics60d.lib"
# ADD LIB32 /nologo /out:"..\SDK\Library\DebugMemory\Wm4Physics60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy /y Intersection\*.h ..\SDK\Include	copy /y LCPSolver\*.h ..\SDK\Include	copy /y ParticleSystem\*.h ..\SDK\Include	copy /y RigidBody\*.h ..\SDK\Include	copy /y *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibPhysics_VC60 - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "Intersection" /I "LCPSolver" /I "ParticleSystem" /I "RigidBody" /I "..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4PhysicsPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\SDK\Library\Release\Wm4Physics60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy /y Intersection\*.h ..\SDK\Include	copy /y LCPSolver\*.h ..\SDK\Include	copy /y ParticleSystem\*.h ..\SDK\Include	copy /y RigidBody\*.h ..\SDK\Include	copy /y *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibPhysics_VC60 - Win32 Release Memory"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /I "Approximation" /I "Collision" /I "Containment" /I "Controllers" /I "Curves" /I "Detail" /I "Distance" /I "Effects" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Math" /I "Meshes" /I "Miscellaneous" /I "Numerics" /I "ObjectSystem" /I "Physics" /I "RationalArithmetic" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "System" /I "Terrain" /I "Tessellation" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "Intersection" /I "LCPSolver" /I "ParticleSystem" /I "RigidBody" /I "..\SDK\Include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /D "WM4_MEMORY_MANAGER" /Yu"Wm4PhysicsPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Release\Wm3Physics60.lib"
# ADD LIB32 /nologo /out:"..\SDK\Library\ReleaseMemory\Wm4Physics60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy /y Intersection\*.h ..\SDK\Include	copy /y LCPSolver\*.h ..\SDK\Include	copy /y ParticleSystem\*.h ..\SDK\Include	copy /y RigidBody\*.h ..\SDK\Include	copy /y *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibPhysics_VC60 - Win32 NoPCH"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "LibPhysics_VC60___Win32_NoPCH"
# PROP BASE Intermediate_Dir "LibPhysics_VC60___Win32_NoPCH"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NoPCH\VC60"
# PROP Intermediate_Dir "NoPCH\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Approximation" /I "Collision" /I "Containment" /I "Controllers" /I "Curves" /I "Detail" /I "Distance" /I "Effects" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Math" /I "Meshes" /I "Miscellaneous" /I "Numerics" /I "ObjectSystem" /I "Physics" /I "RationalArithmetic" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "System" /I "Terrain" /I "Tessellation" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "WM3_USE_PRECOMPILED_HEADERS" /Yu"Wm3PhysicsPCH.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Intersection" /I "LCPSolver" /I "ParticleSystem" /I "RigidBody" /I "..\SDK\Include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Debug\Wm3Physics60d.lib"
# ADD LIB32 /nologo /out:"..\SDK\Library\NoPCH\Wm4Physics60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy /y Intersection\*.h ..\SDK\Include	copy /y LCPSolver\*.h ..\SDK\Include	copy /y ParticleSystem\*.h ..\SDK\Include	copy /y RigidBody\*.h ..\SDK\Include	copy /y *.h ..\SDK\Include
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "LibPhysics_VC60 - Win32 Debug"
# Name "LibPhysics_VC60 - Win32 Debug Memory"
# Name "LibPhysics_VC60 - Win32 Release"
# Name "LibPhysics_VC60 - Win32 Release Memory"
# Name "LibPhysics_VC60 - Win32 NoPCH"
# Begin Group "Intersection"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Intersection\Wm4ExtremalQuery3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4ExtremalQuery3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4ExtremalQuery3BSP.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4ExtremalQuery3BSP.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4ExtremalQuery3PRJ.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4ExtremalQuery3PRJ.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntersectingBoxes.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntersectingBoxes.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntersectingIntervals.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntersectingIntervals.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntersectingRectangles.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntersectingRectangles.h
# End Source File
# End Group
# Begin Group "LCPSolver"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\LCPSolver\Wm4LCPPolyDist.cpp
# End Source File
# Begin Source File

SOURCE=.\LCPSolver\Wm4LCPPolyDist.h
# End Source File
# Begin Source File

SOURCE=.\LCPSolver\Wm4LCPSolver.cpp
# End Source File
# Begin Source File

SOURCE=.\LCPSolver\Wm4LCPSolver.h
# End Source File
# End Group
# Begin Group "ParticleSystem"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ParticleSystem\Wm4MassSpringArbitrary.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem\Wm4MassSpringArbitrary.h
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem\Wm4MassSpringCurve.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem\Wm4MassSpringCurve.h
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem\Wm4MassSpringSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem\Wm4MassSpringSurface.h
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem\Wm4MassSpringVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem\Wm4MassSpringVolume.h
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem\Wm4ParticleSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\ParticleSystem\Wm4ParticleSystem.h
# End Source File
# End Group
# Begin Group "RigidBody"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\RigidBody\Wm4PolyhedralMassProperties.cpp
# End Source File
# Begin Source File

SOURCE=.\RigidBody\Wm4PolyhedralMassProperties.h
# End Source File
# Begin Source File

SOURCE=.\RigidBody\Wm4RigidBody.cpp
# End Source File
# Begin Source File

SOURCE=.\RigidBody\Wm4RigidBody.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Wm4Physics.h
# End Source File
# Begin Source File

SOURCE=.\Wm4PhysicsLIB.h
# End Source File
# Begin Source File

SOURCE=.\Wm4PhysicsPCH.cpp

!IF  "$(CFG)" == "LibPhysics_VC60 - Win32 Debug"

# ADD CPP /Yc"Wm4PhysicsPCH.h"

!ELSEIF  "$(CFG)" == "LibPhysics_VC60 - Win32 Debug Memory"

# ADD CPP /Yc"Wm4PhysicsPCH.h"

!ELSEIF  "$(CFG)" == "LibPhysics_VC60 - Win32 Release"

# ADD CPP /Yc"Wm4PhysicsPCH.h"

!ELSEIF  "$(CFG)" == "LibPhysics_VC60 - Win32 Release Memory"

# ADD CPP /Yc"Wm4PhysicsPCH.h"

!ELSEIF  "$(CFG)" == "LibPhysics_VC60 - Win32 NoPCH"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Wm4PhysicsPCH.h
# End Source File
# End Target
# End Project

