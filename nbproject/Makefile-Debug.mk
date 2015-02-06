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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Group.o \
	${OBJECTDIR}/src/Reader.o \
	${OBJECTDIR}/src/Record.o \
	${OBJECTDIR}/src/Records/ALCH.o \
	${OBJECTDIR}/src/Records/AMMO.o \
	${OBJECTDIR}/src/Records/ARMA.o \
	${OBJECTDIR}/src/Records/ARMO.o \
	${OBJECTDIR}/src/Records/BOOK.o \
	${OBJECTDIR}/src/Records/CLAS.o \
	${OBJECTDIR}/src/Records/CONT.o \
	${OBJECTDIR}/src/Records/EXPL.o \
	${OBJECTDIR}/src/Records/FACT.o \
	${OBJECTDIR}/src/Records/FLST.o \
	${OBJECTDIR}/src/Records/GLOB.o \
	${OBJECTDIR}/src/Records/GMST.o \
	${OBJECTDIR}/src/Records/KEYM.o \
	${OBJECTDIR}/src/Records/MISC.o \
	${OBJECTDIR}/src/Records/NPC_.o \
	${OBJECTDIR}/src/Records/REFR.o \
	${OBJECTDIR}/src/Records/SCPT.o \
	${OBJECTDIR}/src/Records/TERM.o \
	${OBJECTDIR}/src/Records/TES4.o \
	${OBJECTDIR}/src/Records/WEAP.o \
	${OBJECTDIR}/src/SubRecord.o \
	${OBJECTDIR}/src/Subrecords/subEDID.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-pedantic-errors -pedantic -Wfatal-errors -Wextra -Wall -std=gnu++1y -m32 -DDEBUG
CXXFLAGS=-pedantic-errors -pedantic -Wfatal-errors -Wextra -Wall -std=gnu++1y -m32 -DDEBUG

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader2.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader2.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader2.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader2.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader2.a

${OBJECTDIR}/src/Group.o: src/Group.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Group.o src/Group.cpp

${OBJECTDIR}/src/Reader.o: src/Reader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Reader.o src/Reader.cpp

${OBJECTDIR}/src/Record.o: src/Record.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Record.o src/Record.cpp

${OBJECTDIR}/src/Records/ALCH.o: src/Records/ALCH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ALCH.o src/Records/ALCH.cpp

${OBJECTDIR}/src/Records/AMMO.o: src/Records/AMMO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/AMMO.o src/Records/AMMO.cpp

${OBJECTDIR}/src/Records/ARMA.o: src/Records/ARMA.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ARMA.o src/Records/ARMA.cpp

${OBJECTDIR}/src/Records/ARMO.o: src/Records/ARMO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ARMO.o src/Records/ARMO.cpp

${OBJECTDIR}/src/Records/BOOK.o: src/Records/BOOK.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/BOOK.o src/Records/BOOK.cpp

${OBJECTDIR}/src/Records/CLAS.o: src/Records/CLAS.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/CLAS.o src/Records/CLAS.cpp

${OBJECTDIR}/src/Records/CONT.o: src/Records/CONT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/CONT.o src/Records/CONT.cpp

${OBJECTDIR}/src/Records/EXPL.o: src/Records/EXPL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/EXPL.o src/Records/EXPL.cpp

${OBJECTDIR}/src/Records/FACT.o: src/Records/FACT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/FACT.o src/Records/FACT.cpp

${OBJECTDIR}/src/Records/FLST.o: src/Records/FLST.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/FLST.o src/Records/FLST.cpp

${OBJECTDIR}/src/Records/GLOB.o: src/Records/GLOB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/GLOB.o src/Records/GLOB.cpp

${OBJECTDIR}/src/Records/GMST.o: src/Records/GMST.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/GMST.o src/Records/GMST.cpp

${OBJECTDIR}/src/Records/KEYM.o: src/Records/KEYM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/KEYM.o src/Records/KEYM.cpp

${OBJECTDIR}/src/Records/MISC.o: src/Records/MISC.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/MISC.o src/Records/MISC.cpp

${OBJECTDIR}/src/Records/NPC_.o: src/Records/NPC_.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/NPC_.o src/Records/NPC_.cpp

${OBJECTDIR}/src/Records/REFR.o: src/Records/REFR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/REFR.o src/Records/REFR.cpp

${OBJECTDIR}/src/Records/SCPT.o: src/Records/SCPT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/SCPT.o src/Records/SCPT.cpp

${OBJECTDIR}/src/Records/TERM.o: src/Records/TERM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/TERM.o src/Records/TERM.cpp

${OBJECTDIR}/src/Records/TES4.o: src/Records/TES4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/TES4.o src/Records/TES4.cpp

${OBJECTDIR}/src/Records/WEAP.o: src/Records/WEAP.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/WEAP.o src/Records/WEAP.cpp

${OBJECTDIR}/src/SubRecord.o: src/SubRecord.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SubRecord.o src/SubRecord.cpp

${OBJECTDIR}/src/Subrecords/subEDID.o: src/Subrecords/subEDID.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Subrecords
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/F/SDK/boost_1_55_0 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Subrecords/subEDID.o src/Subrecords/subEDID.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader2.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
