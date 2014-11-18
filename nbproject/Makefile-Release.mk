#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Reader.o \
	${OBJECTDIR}/src/Record.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/recGMST.o \
	${OBJECTDIR}/src/recTES4.o \
	${OBJECTDIR}/src/recWEAP.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esx-reader.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esx-reader.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esx-reader ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Reader.o: src/Reader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../RWA-Lib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Reader.o src/Reader.cpp

${OBJECTDIR}/src/Record.o: src/Record.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../RWA-Lib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Record.o src/Record.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../RWA-Lib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/recGMST.o: src/recGMST.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../RWA-Lib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/recGMST.o src/recGMST.cpp

${OBJECTDIR}/src/recTES4.o: src/recTES4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../RWA-Lib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/recTES4.o src/recTES4.cpp

${OBJECTDIR}/src/recWEAP.o: src/recWEAP.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -I../RWA-Lib/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/recWEAP.o src/recWEAP.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/esx-reader.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
