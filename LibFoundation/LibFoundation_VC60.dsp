# Microsoft Developer Studio Project File - Name="LibFoundation_VC60" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=LibFoundation_VC60 - Win32 NoPCH
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "LibFoundation_VC60.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "LibFoundation_VC60.mak" CFG="LibFoundation_VC60 - Win32 NoPCH"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "LibFoundation_VC60 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "LibFoundation_VC60 - Win32 Debug Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "LibFoundation_VC60 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "LibFoundation_VC60 - Win32 Release Memory" (based on "Win32 (x86) Static Library")
!MESSAGE "LibFoundation_VC60 - Win32 NoPCH" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "LibFoundation_VC60 - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Approximation" /I "ComputationalGeometry" /I "Containment" /I "Curves" /I "Distance" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Mathematics" /I "Meshes" /I "Miscellaneous" /I "NumericalAnalysis" /I "Surfaces" /I "System" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4FoundationPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\SDK\Library\Debug\Wm4Foundation60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Approximation\*.h ..\SDK\Include	copy ComputationalGeometry\*.h ..\SDK\Include	copy ComputationalGeometry\*.inl ..\SDK\Include	copy Containment\*.h ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Distance\*.h ..\SDK\Include	copy ImageAnalysis\*.h ..\SDK\Include	copy ImageAnalysis\*.inl ..\SDK\Include	copy Interpolation\*.h ..\SDK\Include	copy Intersection\*.h ..\SDK\Include	copy Mathematics\*.h ..\SDK\Include	copy Mathematics\*.inl ..\SDK\Include	copy Meshes\*.h ..\SDK\Include	copy Meshes\*.inl ..\SDK\Include	copy Miscellaneous\*.h ..\SDK\Include	copy NumericalAnalysis\*.h ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy System\*.h ..\SDK\Include	copy System\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibFoundation_VC60 - Win32 Debug Memory"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Approximation" /I "ComputationalGeometry" /I "Containment" /I "Curves" /I "Distance" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Mathematics" /I "Meshes" /I "Miscellaneous" /I "NumericalAnalysis" /I "Surfaces" /I "System" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /D "WM4_MEMORY_MANAGER" /Yu"Wm4FoundationPCH.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Debug\Wm3Foundation60d.lib"
# ADD LIB32 /nologo /out:"..\SDK\Library\DebugMemory\Wm4Foundation60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Approximation\*.h ..\SDK\Include	copy ComputationalGeometry\*.h ..\SDK\Include	copy ComputationalGeometry\*.inl ..\SDK\Include	copy Containment\*.h ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Distance\*.h ..\SDK\Include	copy ImageAnalysis\*.h ..\SDK\Include	copy ImageAnalysis\*.inl ..\SDK\Include	copy Interpolation\*.h ..\SDK\Include	copy Intersection\*.h ..\SDK\Include	copy Mathematics\*.h ..\SDK\Include	copy Mathematics\*.inl ..\SDK\Include	copy Meshes\*.h ..\SDK\Include	copy Meshes\*.inl ..\SDK\Include	copy Miscellaneous\*.h ..\SDK\Include	copy NumericalAnalysis\*.h ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy System\*.h ..\SDK\Include	copy System\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibFoundation_VC60 - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "Approximation" /I "ComputationalGeometry" /I "Containment" /I "Curves" /I "Distance" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Mathematics" /I "Meshes" /I "Miscellaneous" /I "NumericalAnalysis" /I "Surfaces" /I "System" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /Yu"Wm4FoundationPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\SDK\Library\Release\Wm4Foundation60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Approximation\*.h ..\SDK\Include	copy ComputationalGeometry\*.h ..\SDK\Include	copy ComputationalGeometry\*.inl ..\SDK\Include	copy Containment\*.h ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Distance\*.h ..\SDK\Include	copy ImageAnalysis\*.h ..\SDK\Include	copy ImageAnalysis\*.inl ..\SDK\Include	copy Interpolation\*.h ..\SDK\Include	copy Intersection\*.h ..\SDK\Include	copy Mathematics\*.h ..\SDK\Include	copy Mathematics\*.inl ..\SDK\Include	copy Meshes\*.h ..\SDK\Include	copy Meshes\*.inl ..\SDK\Include	copy Miscellaneous\*.h ..\SDK\Include	copy NumericalAnalysis\*.h ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy System\*.h ..\SDK\Include	copy System\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibFoundation_VC60 - Win32 Release Memory"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /I ".\\" /I "Approximation" /I "ComputationalGeometry" /I "Containment" /I "Curves" /I "Distance" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Mathematics" /I "Meshes" /I "Miscellaneous" /I "NumericalAnalysis" /I "Surfaces" /I "System" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "WM4_USE_PRECOMPILED_HEADERS" /D "WM4_MEMORY_MANAGER" /Yu"Wm4FoundationPCH.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Release\Wm3Foundation60.lib"
# ADD LIB32 /nologo /out:"..\SDK\Library\ReleaseMemory\Wm4Foundation60.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Approximation\*.h ..\SDK\Include	copy ComputationalGeometry\*.h ..\SDK\Include	copy ComputationalGeometry\*.inl ..\SDK\Include	copy Containment\*.h ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Distance\*.h ..\SDK\Include	copy ImageAnalysis\*.h ..\SDK\Include	copy ImageAnalysis\*.inl ..\SDK\Include	copy Interpolation\*.h ..\SDK\Include	copy Intersection\*.h ..\SDK\Include	copy Mathematics\*.h ..\SDK\Include	copy Mathematics\*.inl ..\SDK\Include	copy Meshes\*.h ..\SDK\Include	copy Meshes\*.inl ..\SDK\Include	copy Miscellaneous\*.h ..\SDK\Include	copy NumericalAnalysis\*.h ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy System\*.h ..\SDK\Include	copy System\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ELSEIF  "$(CFG)" == "LibFoundation_VC60 - Win32 NoPCH"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "LibFoundation_VC60___Win32_NoPCH"
# PROP BASE Intermediate_Dir "LibFoundation_VC60___Win32_NoPCH"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "NoPCH\VC60"
# PROP Intermediate_Dir "NoPCH\VC60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Approximation" /I "Collision" /I "Containment" /I "Controllers" /I "Curves" /I "Detail" /I "Distance" /I "Effects" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Math" /I "Meshes" /I "Miscellaneous" /I "Numerics" /I "ObjectSystem" /I "Physics" /I "RationalArithmetic" /I "SceneGraph" /I "Shaders" /I "SharedArrays" /I "Sorting" /I "Surfaces" /I "System" /I "Terrain" /I "Tessellation" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "WM3_USE_PRECOMPILED_HEADERS" /Yu"Wm3FoundationPCH.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "Approximation" /I "ComputationalGeometry" /I "Containment" /I "Curves" /I "Distance" /I "ImageAnalysis" /I "Interpolation" /I "Intersection" /I "Mathematics" /I "Meshes" /I "Miscellaneous" /I "NumericalAnalysis" /I "Surfaces" /I "System" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\Library\Debug\Wm3Foundation60d.lib"
# ADD LIB32 /nologo /out:"..\SDK\Library\NoPCH\Wm4Foundation60d.lib"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Cmds=copy Approximation\*.h ..\SDK\Include	copy ComputationalGeometry\*.h ..\SDK\Include	copy ComputationalGeometry\*.inl ..\SDK\Include	copy Containment\*.h ..\SDK\Include	copy Curves\*.h ..\SDK\Include	copy Distance\*.h ..\SDK\Include	copy ImageAnalysis\*.h ..\SDK\Include	copy ImageAnalysis\*.inl ..\SDK\Include	copy Interpolation\*.h ..\SDK\Include	copy Intersection\*.h ..\SDK\Include	copy Mathematics\*.h ..\SDK\Include	copy Mathematics\*.inl ..\SDK\Include	copy Meshes\*.h ..\SDK\Include	copy Meshes\*.inl ..\SDK\Include	copy Miscellaneous\*.h ..\SDK\Include	copy NumericalAnalysis\*.h ..\SDK\Include	copy Surfaces\*.h ..\SDK\Include	copy System\*.h ..\SDK\Include	copy System\*.inl ..\SDK\Include	copy *.h ..\SDK\Include
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "LibFoundation_VC60 - Win32 Debug"
# Name "LibFoundation_VC60 - Win32 Debug Memory"
# Name "LibFoundation_VC60 - Win32 Release"
# Name "LibFoundation_VC60 - Win32 Release Memory"
# Name "LibFoundation_VC60 - Win32 NoPCH"
# Begin Group "Approximation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Approximation\Wm4ApprCircleFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprCircleFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprCylinderFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprCylinderFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprEllipseFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprEllipseFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprEllipsoidFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprEllipsoidFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprGaussPointsFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprGaussPointsFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprGaussPointsFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprGaussPointsFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprLineFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprLineFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprLineFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprLineFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprParaboloidFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprParaboloidFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprPlaneFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprPlaneFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprPolyFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprPolyFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprPolyFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprPolyFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprPolyFit4.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprPolyFit4.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprQuadraticFit2.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprQuadraticFit2.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprQuadraticFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprQuadraticFit3.h
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprSphereFit3.cpp
# End Source File
# Begin Source File

SOURCE=.\Approximation\Wm4ApprSphereFit3.h
# End Source File
# End Group
# Begin Group "ComputationalGeometry"

# PROP Default_Filter ""
# Begin Group "ConvexHull"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4ConvexHull.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4ConvexHull.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4ConvexHull1.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4ConvexHull1.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4ConvexHull2.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4ConvexHull2.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4ConvexHull3.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4ConvexHull3.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4HullEdge2.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4HullEdge2.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4HullTriangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4HullTriangle3.h
# End Source File
# End Group
# Begin Group "Delaunay"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Delaunay.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Delaunay.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Delaunay1.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Delaunay1.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Delaunay2.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Delaunay2.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Delaunay3.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Delaunay3.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4DelPolygonEdge.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4DelPolygonEdge.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4DelPolyhedronFace.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4DelPolyhedronFace.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4DelTetrahedron.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4DelTetrahedron.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4DelTriangle.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4DelTriangle.h
# End Source File
# End Group
# Begin Group "Query"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2Filtered.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2Filtered.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2Int64.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2Int64.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2TInteger.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2TInteger.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2TRational.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query2TRational.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3Filtered.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3Filtered.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3Int64.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3Int64.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3TInteger.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3TInteger.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3TRational.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4Query3TRational.inl
# End Source File
# End Group
# Begin Group "RationalArithmetic"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4IVector2.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4IVector2.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4IVector3.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4IVector3.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4RVector2.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4RVector2.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4RVector3.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4RVector3.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TInteger.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TInteger.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TIVector.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TIVector.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TRational.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TRational.inl
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TRVector.h
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TRVector.inl
# End Source File
# End Group
# Begin Group "Triangulation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TriangulateEC.cpp
# End Source File
# Begin Source File

SOURCE=.\ComputationalGeometry\Wm4TriangulateEC.h
# End Source File
# End Group
# End Group
# Begin Group "Containment"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Containment\Wm4ContBox2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContBox2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContBox3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContBox3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContCapsule3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContCapsule3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContCircle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContCircle2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContCylinder3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContCylinder3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContEllipse2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContEllipse2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContEllipsoid3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContEllipsoid3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContLozenge3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContLozenge3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContPointInPolygon2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContPointInPolygon2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContScribeCircle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContScribeCircle2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContScribeCircle3Sphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContScribeCircle3Sphere3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContSeparatePoints2.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContSeparatePoints2.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContSeparatePoints3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContSeparatePoints3.h
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContSphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Containment\Wm4ContSphere3.h
# End Source File
# End Group
# Begin Group "Curves"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Curves\Wm4BezierCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BezierCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BezierCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BezierCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineBasis.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineBasis.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineFit.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineFit.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineFitBasis.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineFitBasis.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineGeodesic.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineGeodesic.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineReduction.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4BSplineReduction.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4CubicPolynomialCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4CubicPolynomialCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4CubicPolynomialCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4CubicPolynomialCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4Curve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4Curve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4Curve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4Curve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4EllipsoidGeodesic.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4EllipsoidGeodesic.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4MultipleCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4MultipleCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4MultipleCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4MultipleCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4NaturalSpline2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4NaturalSpline2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4NaturalSpline3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4NaturalSpline3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4NURBSCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4NURBSCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4NURBSCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4NURBSCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4PolynomialCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4PolynomialCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4PolynomialCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4PolynomialCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4RiemannianGeodesic.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4RiemannianGeodesic.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4SingleCurve2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4SingleCurve2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4SingleCurve3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4SingleCurve3.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4TCBSpline2.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4TCBSpline2.h
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4TCBSpline3.cpp
# End Source File
# Begin Source File

SOURCE=.\Curves\Wm4TCBSpline3.h
# End Source File
# End Group
# Begin Group "Distance"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Distance\Wm4Distance.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4Distance.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistCircle3Circle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistCircle3Circle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine2Line2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine2Line2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine2Ray2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine2Ray2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine2Segment2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine2Segment2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Circle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Circle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Line3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Line3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Ray3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Ray3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Rectangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Rectangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Segment3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Segment3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistLine3Triangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay2Ray2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay2Ray2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay2Segment2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay2Segment2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Ray3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Ray3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Rectangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Rectangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Segment3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Segment3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRay3Triangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRectangle3Rectangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistRectangle3Rectangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment2Segment2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment2Segment2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment3Rectangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment3Rectangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment3Segment3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment3Segment3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistSegment3Triangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistTriangle3Rectangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistTriangle3Rectangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistTriangle3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistTriangle3Triangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Box2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Box2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Ellipse2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Ellipse2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Line2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Line2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Quadratic2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Quadratic2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Ray2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Ray2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Segment2.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector2Segment2.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Circle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Circle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Ellipsoid3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Ellipsoid3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Frustum3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Frustum3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Line3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Line3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Plane3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Plane3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Quadratic3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Quadratic3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Ray3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Ray3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Rectangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Rectangle3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Segment3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Segment3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Tetrahedron3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Tetrahedron3.h
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Distance\Wm4DistVector3Triangle3.h
# End Source File
# End Group
# Begin Group "ImageAnalysis"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Binary2D.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Binary2D.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Binary3D.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Binary3D.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Element.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Element.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Element.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4ExtractSurfaceCubes.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4ExtractSurfaceCubes.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4ExtractSurfaceCubes.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4ExtractSurfaceTetra.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4ExtractSurfaceTetra.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4FastBlur.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4FastBlur.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4ImageConvert.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4ImageConvert.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Images.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Images.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Lattice.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Lattice.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4Lattice.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4RasterDrawing.cpp
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4RasterDrawing.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4TImage.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4TImage.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4TImage2D.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4TImage2D.inl
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4TImage3D.h
# End Source File
# Begin Source File

SOURCE=.\ImageAnalysis\Wm4TImage3D.inl
# End Source File
# End Group
# Begin Group "Interpolation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkima1.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkima1.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkimaNonuniform1.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkimaNonuniform1.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkimaUniform1.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkimaUniform1.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkimaUniform2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkimaUniform2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkimaUniform3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpAkimaUniform3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBicubic2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBicubic2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBilinear2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBilinear2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform1.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform1.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform4.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniform4.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniformN.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpBSplineUniformN.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpLinearNonuniform2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpLinearNonuniform2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpLinearNonuniform3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpLinearNonuniform3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpQdrNonuniform2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpQdrNonuniform2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpSphere2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpSphere2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpThinPlateSpline2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpThinPlateSpline2.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpThinPlateSpline3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpThinPlateSpline3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpTricubic3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpTricubic3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpTrilinear3.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpTrilinear3.h
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpVectorField2.cpp
# End Source File
# Begin Source File

SOURCE=.\Interpolation\Wm4IntpVectorField2.h
# End Source File
# End Group
# Begin Group "Intersection"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Intersection\Wm4Intersector.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4Intersector.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4Intersector1.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4Intersector1.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrArc2Arc2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrArc2Arc2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrArc2Circle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrArc2Circle2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox2Box2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox2Box2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox2Circle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox2Circle2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox3Frustum3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox3Frustum3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox3Sphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrBox3Sphere3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrCapsule3Capsule3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrCapsule3Capsule3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrCircle2Circle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrCircle2Circle2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrCircle3Plane3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrCircle3Plane3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrEllipse2Ellipse2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrEllipse2Ellipse2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLinComp2LinComp2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLinComp2LinComp2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLinComp2Triangle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLinComp2Triangle2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine2Arc2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine2Arc2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine2Box2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine2Box2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine2Circle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine2Circle2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Capsule3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Capsule3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Cone3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Cone3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Cylinder3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Cylinder3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Ellipsoid3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Ellipsoid3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Lozenge3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Lozenge3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Plane3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Plane3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Sphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Sphere3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Torus3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Torus3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLine3Triangle3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLozenge3Lozenge3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrLozenge3Lozenge3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Capsule3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Capsule3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Cylinder3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Cylinder3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Ellipsoid3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Ellipsoid3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Lozenge3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Lozenge3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Plane3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Plane3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Sphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Sphere3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrPlane3Triangle3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay2Arc2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay2Arc2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay2Box2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay2Box2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay2Circle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay2Circle2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Capsule3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Capsule3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Cylinder3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Cylinder3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Ellipsoid3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Ellipsoid3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Lozenge3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Lozenge3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Plane3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Plane3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Sphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Sphere3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrRay3Triangle3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment2Arc2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment2Arc2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment2Box2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment2Box2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment2Circle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment2Circle2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Box3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Box3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Capsule3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Capsule3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Cylinder3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Cylinder3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Ellipsoid3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Ellipsoid3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Lozenge3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Lozenge3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Plane3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Plane3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Sphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Sphere3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSegment3Triangle3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSphere3Cone3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSphere3Cone3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSphere3Frustum3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSphere3Frustum3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSphere3Sphere3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrSphere3Sphere3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrTetrahedron3Tetrahedron3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrTetrahedron3Tetrahedron3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrTriangle2Triangle2.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrTriangle2Triangle2.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrTriangle3Cone3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrTriangle3Cone3.h
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrTriangle3Triangle3.cpp
# End Source File
# Begin Source File

SOURCE=.\Intersection\Wm4IntrTriangle3Triangle3.h
# End Source File
# End Group
# Begin Group "Mathematics"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Mathematics\Wm4Arc2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Arc2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4AxisAlignedBox2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4AxisAlignedBox2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4AxisAlignedBox3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4AxisAlignedBox3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4BandedMatrix.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4BandedMatrix.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4BitHacks.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4BitHacks.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Box2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Box2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Box3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Box3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4BSplineVolume.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4BSplineVolume.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Capsule3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Capsule3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Circle2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Circle2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Circle3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Circle3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4ColorRGB.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4ColorRGB.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4ColorRGB.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4ColorRGBA.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4ColorRGBA.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4ColorRGBA.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Cone3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Cone3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4ConvexPolyhedron3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4ConvexPolyhedron3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Cylinder3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Cylinder3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Ellipse2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Ellipse2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Ellipsoid3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Ellipsoid3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Frustum3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Frustum3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4GMatrix.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4GMatrix.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4GVector.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4GVector.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4LinComp.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4LinComp.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4LinComp2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4LinComp2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4LinComp3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4LinComp3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Line2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Line2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Line3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Line3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Lozenge3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Lozenge3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Mapper2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Mapper2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Mapper3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Mapper3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Math.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Math.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Math.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4MathMCR.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Matrix2.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Matrix2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Matrix2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Matrix3.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Matrix3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Matrix3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Matrix4.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Matrix4.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Matrix4.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Plane3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Plane3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Polyhedron3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Polyhedron3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Polynomial1.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Polynomial1.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Quadratic2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Quadratic2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Quadratic3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Quadratic3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Quaternion.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Quaternion.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Quaternion.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Ray2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Ray2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Ray3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Ray3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Rectangle3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Rectangle3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Segment2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Segment2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Segment3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Segment3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Sphere3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Sphere3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Tetrahedron3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Tetrahedron3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Torus3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Torus3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Triangle2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Triangle2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Triangle3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Triangle3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Vector2.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Vector2.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Vector2.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Vector3.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Vector3.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Vector3.inl
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Vector4.cpp
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Vector4.h
# End Source File
# Begin Source File

SOURCE=.\Mathematics\Wm4Vector4.inl
# End Source File
# End Group
# Begin Group "Meshes"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Meshes\Wm4BasicMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4BasicMesh.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4BasicMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4ConformalMap.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4ConformalMap.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4EdgeKey.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4EdgeKey.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4ETManifoldMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4ETManifoldMesh.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4ETManifoldMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4ETNonmanifoldMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4ETNonmanifoldMesh.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4ETNonmanifoldMesh.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4MeshCurvature.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4MeshCurvature.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4MeshSmoother.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4MeshSmoother.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4PlanarGraph.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4PlanarGraph.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4TriangleKey.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4TriangleKey.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4UniqueVerticesTriangles.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4UniqueVerticesTriangles.inl
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4VEManifoldMesh.cpp
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4VEManifoldMesh.h
# End Source File
# Begin Source File

SOURCE=.\Meshes\Wm4VEManifoldMesh.inl
# End Source File
# End Group
# Begin Group "Miscellaneous"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Miscellaneous\Wm4GridGraph2.cpp
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4GridGraph2.h
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4NormalCompression.cpp
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4NormalCompression.h
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4PerspProjEllipsoid.cpp
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4PerspProjEllipsoid.h
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4QuadToQuadTransforms.cpp
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4QuadToQuadTransforms.h
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4RandomHypersphere.cpp
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4RandomHypersphere.h
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4TangentsToCircles.cpp
# End Source File
# Begin Source File

SOURCE=.\Miscellaneous\Wm4TangentsToCircles.h
# End Source File
# End Group
# Begin Group "NumericalAnalysis"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Bisect1.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Bisect1.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Bisect2.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Bisect2.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Bisect3.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Bisect3.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Eigen.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Eigen.h
# End Source File
# Begin Source File

SOURCE=.\Wm4Foundation.h
# End Source File
# Begin Source File

SOURCE=.\Wm4FoundationLIB.h
# End Source File
# Begin Source File

SOURCE=.\Wm4FoundationPCH.cpp

!IF  "$(CFG)" == "LibFoundation_VC60 - Win32 Debug"

# ADD CPP /Yc"Wm4FoundationPCH.h"

!ELSEIF  "$(CFG)" == "LibFoundation_VC60 - Win32 Debug Memory"

# ADD CPP /Yc"Wm4FoundationPCH.h"

!ELSEIF  "$(CFG)" == "LibFoundation_VC60 - Win32 Release"

# ADD CPP /Yc"Wm4FoundationPCH.h"

!ELSEIF  "$(CFG)" == "LibFoundation_VC60 - Win32 Release Memory"

# ADD CPP /Yc"Wm4FoundationPCH.h"

!ELSEIF  "$(CFG)" == "LibFoundation_VC60 - Win32 NoPCH"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Wm4FoundationPCH.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Integrate1.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Integrate1.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4LinearSystem.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4LinearSystem.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Minimize1.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4Minimize1.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4MinimizeN.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4MinimizeN.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeEuler.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeEuler.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeImplicitEuler.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeImplicitEuler.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeMidpoint.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeMidpoint.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeRungeKutta4.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeRungeKutta4.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeSolver.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4OdeSolver.h
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4PolynomialRoots.cpp
# End Source File
# Begin Source File

SOURCE=.\NumericalAnalysis\Wm4PolynomialRoots.h
# End Source File
# End Group
# Begin Group "Surfaces"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Surfaces\Wm4BSplineRectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4BSplineRectangle.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4ImplicitSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4ImplicitSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4NURBSRectangle.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4NURBSRectangle.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4ParametricSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4ParametricSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4QuadricSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4QuadricSurface.h
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4Surface.cpp
# End Source File
# Begin Source File

SOURCE=.\Surfaces\Wm4Surface.h
# End Source File
# End Group
# Begin Group "System"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\System\Wm4Command.cpp
# End Source File
# Begin Source File

SOURCE=.\System\Wm4Command.h
# End Source File
# Begin Source File

SOURCE=.\System\Wm4Memory.cpp
# End Source File
# Begin Source File

SOURCE=.\System\Wm4Memory.h
# End Source File
# Begin Source File

SOURCE=.\System\Wm4Memory.inl
# End Source File
# Begin Source File

SOURCE=.\System\Wm4Platforms.h
# End Source File
# Begin Source File

SOURCE=.\System\Wm4System.cpp
# End Source File
# Begin Source File

SOURCE=.\System\Wm4System.h
# End Source File
# Begin Source File

SOURCE=.\System\Wm4System.inl
# End Source File
# Begin Source File

SOURCE=.\System\Wm4THashSet.h
# End Source File
# Begin Source File

SOURCE=.\System\Wm4THashSet.inl
# End Source File
# Begin Source File

SOURCE=.\System\Wm4THashTable.h
# End Source File
# Begin Source File

SOURCE=.\System\Wm4THashTable.inl
# End Source File
# Begin Source File

SOURCE=.\System\Wm4TSmallUnorderedSet.h
# End Source File
# Begin Source File

SOURCE=.\System\Wm4TSmallUnorderedSet.inl
# End Source File
# Begin Source File

SOURCE=.\System\Wm4TStringHashTable.h
# End Source File
# Begin Source File

SOURCE=.\System\Wm4TStringHashTable.inl
# End Source File
# Begin Source File

SOURCE=.\System\Wm4TTuple.h
# End Source File
# Begin Source File

SOURCE=.\System\Wm4TTuple.inl
# End Source File
# End Group
# End Target
# End Project

