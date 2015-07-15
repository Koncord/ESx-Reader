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
	${OBJECTDIR}/src/Groups/GroupCELL.o \
	${OBJECTDIR}/src/Groups/GroupWRLD.o \
	${OBJECTDIR}/src/Reader.o \
	${OBJECTDIR}/src/Record.o \
	${OBJECTDIR}/src/Records/ACHR.o \
	${OBJECTDIR}/src/Records/ACRE.o \
	${OBJECTDIR}/src/Records/ACTI.o \
	${OBJECTDIR}/src/Records/ALCH.o \
	${OBJECTDIR}/src/Records/AMMO.o \
	${OBJECTDIR}/src/Records/ANIO.o \
	${OBJECTDIR}/src/Records/ARMA.o \
	${OBJECTDIR}/src/Records/ARMO.o \
	${OBJECTDIR}/src/Records/BOOK.o \
	${OBJECTDIR}/src/Records/BPTD.o \
	${OBJECTDIR}/src/Records/CAMS.o \
	${OBJECTDIR}/src/Records/CELL.o \
	${OBJECTDIR}/src/Records/CLAS.o \
	${OBJECTDIR}/src/Records/COBJ.o \
	${OBJECTDIR}/src/Records/CONT.o \
	${OBJECTDIR}/src/Records/CPTH.o \
	${OBJECTDIR}/src/Records/CREA.o \
	${OBJECTDIR}/src/Records/CSTY.o \
	${OBJECTDIR}/src/Records/DOBJ.o \
	${OBJECTDIR}/src/Records/DOOR.o \
	${OBJECTDIR}/src/Records/ECZN.o \
	${OBJECTDIR}/src/Records/ENCH.o \
	${OBJECTDIR}/src/Records/EXPL.o \
	${OBJECTDIR}/src/Records/FACT.o \
	${OBJECTDIR}/src/Records/FLST.o \
	${OBJECTDIR}/src/Records/FURN.o \
	${OBJECTDIR}/src/Records/GLOB.o \
	${OBJECTDIR}/src/Records/GMST.o \
	${OBJECTDIR}/src/Records/IDLE.o \
	${OBJECTDIR}/src/Records/IDLM.o \
	${OBJECTDIR}/src/Records/INGR.o \
	${OBJECTDIR}/src/Records/KEYM.o \
	${OBJECTDIR}/src/Records/LIGH.o \
	${OBJECTDIR}/src/Records/LVLI.o \
	${OBJECTDIR}/src/Records/LVLN_LVLC.o \
	${OBJECTDIR}/src/Records/MGEF.o \
	${OBJECTDIR}/src/Records/MISC.o \
	${OBJECTDIR}/src/Records/MSTT.o \
	${OBJECTDIR}/src/Records/NPC_.o \
	${OBJECTDIR}/src/Records/PACK.o \
	${OBJECTDIR}/src/Records/PERK.o \
	${OBJECTDIR}/src/Records/PROJ.o \
	${OBJECTDIR}/src/Records/PWAT.o \
	${OBJECTDIR}/src/Records/QUST.o \
	${OBJECTDIR}/src/Records/RACE.o \
	${OBJECTDIR}/src/Records/RADS.o \
	${OBJECTDIR}/src/Records/REFR.o \
	${OBJECTDIR}/src/Records/REGN.o \
	${OBJECTDIR}/src/Records/SCOL.o \
	${OBJECTDIR}/src/Records/SCPT.o \
	${OBJECTDIR}/src/Records/SPEL.o \
	${OBJECTDIR}/src/Records/STAT.o \
	${OBJECTDIR}/src/Records/TACT.o \
	${OBJECTDIR}/src/Records/TERM.o \
	${OBJECTDIR}/src/Records/TES4.o \
	${OBJECTDIR}/src/Records/WATR.o \
	${OBJECTDIR}/src/Records/WEAP.o \
	${OBJECTDIR}/src/Records/WRLD.o \
	${OBJECTDIR}/src/SubRecord.o \
	${OBJECTDIR}/src/Subrecords/CollectionEffect.o \
	${OBJECTDIR}/src/Subrecords/ConditionCollection.o \
	${OBJECTDIR}/src/Subrecords/DestructionCollection.o \
	${OBJECTDIR}/src/Subrecords/ItemCollection.o \
	${OBJECTDIR}/src/Subrecords/ModelCollection.o \
	${OBJECTDIR}/src/Subrecords/ScriptCollection.o \
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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader.a: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader.a
	${AR} -rv ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader.a ${OBJECTFILES} 
	$(RANLIB) ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader.a

${OBJECTDIR}/src/Group.o: src/Group.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Group.o src/Group.cpp

${OBJECTDIR}/src/Groups/GroupCELL.o: src/Groups/GroupCELL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Groups
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Groups/GroupCELL.o src/Groups/GroupCELL.cpp

${OBJECTDIR}/src/Groups/GroupWRLD.o: src/Groups/GroupWRLD.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Groups
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Groups/GroupWRLD.o src/Groups/GroupWRLD.cpp

${OBJECTDIR}/src/Reader.o: src/Reader.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Reader.o src/Reader.cpp

${OBJECTDIR}/src/Record.o: src/Record.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Record.o src/Record.cpp

${OBJECTDIR}/src/Records/ACHR.o: src/Records/ACHR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ACHR.o src/Records/ACHR.cpp

${OBJECTDIR}/src/Records/ACRE.o: src/Records/ACRE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ACRE.o src/Records/ACRE.cpp

${OBJECTDIR}/src/Records/ACTI.o: src/Records/ACTI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ACTI.o src/Records/ACTI.cpp

${OBJECTDIR}/src/Records/ALCH.o: src/Records/ALCH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ALCH.o src/Records/ALCH.cpp

${OBJECTDIR}/src/Records/AMMO.o: src/Records/AMMO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/AMMO.o src/Records/AMMO.cpp

${OBJECTDIR}/src/Records/ANIO.o: src/Records/ANIO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ANIO.o src/Records/ANIO.cpp

${OBJECTDIR}/src/Records/ARMA.o: src/Records/ARMA.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ARMA.o src/Records/ARMA.cpp

${OBJECTDIR}/src/Records/ARMO.o: src/Records/ARMO.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ARMO.o src/Records/ARMO.cpp

${OBJECTDIR}/src/Records/BOOK.o: src/Records/BOOK.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/BOOK.o src/Records/BOOK.cpp

${OBJECTDIR}/src/Records/BPTD.o: src/Records/BPTD.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/BPTD.o src/Records/BPTD.cpp

${OBJECTDIR}/src/Records/CAMS.o: src/Records/CAMS.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/CAMS.o src/Records/CAMS.cpp

${OBJECTDIR}/src/Records/CELL.o: src/Records/CELL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/CELL.o src/Records/CELL.cpp

${OBJECTDIR}/src/Records/CLAS.o: src/Records/CLAS.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/CLAS.o src/Records/CLAS.cpp

${OBJECTDIR}/src/Records/COBJ.o: src/Records/COBJ.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/COBJ.o src/Records/COBJ.cpp

${OBJECTDIR}/src/Records/CONT.o: src/Records/CONT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/CONT.o src/Records/CONT.cpp

${OBJECTDIR}/src/Records/CPTH.o: src/Records/CPTH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/CPTH.o src/Records/CPTH.cpp

${OBJECTDIR}/src/Records/CREA.o: src/Records/CREA.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/CREA.o src/Records/CREA.cpp

${OBJECTDIR}/src/Records/CSTY.o: src/Records/CSTY.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/CSTY.o src/Records/CSTY.cpp

${OBJECTDIR}/src/Records/DOBJ.o: src/Records/DOBJ.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/DOBJ.o src/Records/DOBJ.cpp

${OBJECTDIR}/src/Records/DOOR.o: src/Records/DOOR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/DOOR.o src/Records/DOOR.cpp

${OBJECTDIR}/src/Records/ECZN.o: src/Records/ECZN.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ECZN.o src/Records/ECZN.cpp

${OBJECTDIR}/src/Records/ENCH.o: src/Records/ENCH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/ENCH.o src/Records/ENCH.cpp

${OBJECTDIR}/src/Records/EXPL.o: src/Records/EXPL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/EXPL.o src/Records/EXPL.cpp

${OBJECTDIR}/src/Records/FACT.o: src/Records/FACT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/FACT.o src/Records/FACT.cpp

${OBJECTDIR}/src/Records/FLST.o: src/Records/FLST.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/FLST.o src/Records/FLST.cpp

${OBJECTDIR}/src/Records/FURN.o: src/Records/FURN.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/FURN.o src/Records/FURN.cpp

${OBJECTDIR}/src/Records/GLOB.o: src/Records/GLOB.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/GLOB.o src/Records/GLOB.cpp

${OBJECTDIR}/src/Records/GMST.o: src/Records/GMST.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/GMST.o src/Records/GMST.cpp

${OBJECTDIR}/src/Records/IDLE.o: src/Records/IDLE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/IDLE.o src/Records/IDLE.cpp

${OBJECTDIR}/src/Records/IDLM.o: src/Records/IDLM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/IDLM.o src/Records/IDLM.cpp

${OBJECTDIR}/src/Records/INGR.o: src/Records/INGR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/INGR.o src/Records/INGR.cpp

${OBJECTDIR}/src/Records/KEYM.o: src/Records/KEYM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/KEYM.o src/Records/KEYM.cpp

${OBJECTDIR}/src/Records/LIGH.o: src/Records/LIGH.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/LIGH.o src/Records/LIGH.cpp

${OBJECTDIR}/src/Records/LVLI.o: src/Records/LVLI.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/LVLI.o src/Records/LVLI.cpp

${OBJECTDIR}/src/Records/LVLN_LVLC.o: src/Records/LVLN_LVLC.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/LVLN_LVLC.o src/Records/LVLN_LVLC.cpp

${OBJECTDIR}/src/Records/MGEF.o: src/Records/MGEF.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/MGEF.o src/Records/MGEF.cpp

${OBJECTDIR}/src/Records/MISC.o: src/Records/MISC.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/MISC.o src/Records/MISC.cpp

${OBJECTDIR}/src/Records/MSTT.o: src/Records/MSTT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/MSTT.o src/Records/MSTT.cpp

${OBJECTDIR}/src/Records/NPC_.o: src/Records/NPC_.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/NPC_.o src/Records/NPC_.cpp

${OBJECTDIR}/src/Records/PACK.o: src/Records/PACK.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/PACK.o src/Records/PACK.cpp

${OBJECTDIR}/src/Records/PERK.o: src/Records/PERK.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/PERK.o src/Records/PERK.cpp

${OBJECTDIR}/src/Records/PROJ.o: src/Records/PROJ.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/PROJ.o src/Records/PROJ.cpp

${OBJECTDIR}/src/Records/PWAT.o: src/Records/PWAT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/PWAT.o src/Records/PWAT.cpp

${OBJECTDIR}/src/Records/QUST.o: src/Records/QUST.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/QUST.o src/Records/QUST.cpp

${OBJECTDIR}/src/Records/RACE.o: src/Records/RACE.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/RACE.o src/Records/RACE.cpp

${OBJECTDIR}/src/Records/RADS.o: src/Records/RADS.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/RADS.o src/Records/RADS.cpp

${OBJECTDIR}/src/Records/REFR.o: src/Records/REFR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/REFR.o src/Records/REFR.cpp

${OBJECTDIR}/src/Records/REGN.o: src/Records/REGN.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/REGN.o src/Records/REGN.cpp

${OBJECTDIR}/src/Records/SCOL.o: src/Records/SCOL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/SCOL.o src/Records/SCOL.cpp

${OBJECTDIR}/src/Records/SCPT.o: src/Records/SCPT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/SCPT.o src/Records/SCPT.cpp

${OBJECTDIR}/src/Records/SPEL.o: src/Records/SPEL.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/SPEL.o src/Records/SPEL.cpp

${OBJECTDIR}/src/Records/STAT.o: src/Records/STAT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/STAT.o src/Records/STAT.cpp

${OBJECTDIR}/src/Records/TACT.o: src/Records/TACT.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/TACT.o src/Records/TACT.cpp

${OBJECTDIR}/src/Records/TERM.o: src/Records/TERM.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/TERM.o src/Records/TERM.cpp

${OBJECTDIR}/src/Records/TES4.o: src/Records/TES4.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/TES4.o src/Records/TES4.cpp

${OBJECTDIR}/src/Records/WATR.o: src/Records/WATR.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/WATR.o src/Records/WATR.cpp

${OBJECTDIR}/src/Records/WEAP.o: src/Records/WEAP.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/WEAP.o src/Records/WEAP.cpp

${OBJECTDIR}/src/Records/WRLD.o: src/Records/WRLD.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Records
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Records/WRLD.o src/Records/WRLD.cpp

${OBJECTDIR}/src/SubRecord.o: src/SubRecord.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/SubRecord.o src/SubRecord.cpp

${OBJECTDIR}/src/Subrecords/CollectionEffect.o: src/Subrecords/CollectionEffect.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Subrecords
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Subrecords/CollectionEffect.o src/Subrecords/CollectionEffect.cpp

${OBJECTDIR}/src/Subrecords/ConditionCollection.o: src/Subrecords/ConditionCollection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Subrecords
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Subrecords/ConditionCollection.o src/Subrecords/ConditionCollection.cpp

${OBJECTDIR}/src/Subrecords/DestructionCollection.o: src/Subrecords/DestructionCollection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Subrecords
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Subrecords/DestructionCollection.o src/Subrecords/DestructionCollection.cpp

${OBJECTDIR}/src/Subrecords/ItemCollection.o: src/Subrecords/ItemCollection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Subrecords
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Subrecords/ItemCollection.o src/Subrecords/ItemCollection.cpp

${OBJECTDIR}/src/Subrecords/ModelCollection.o: src/Subrecords/ModelCollection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Subrecords
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Subrecords/ModelCollection.o src/Subrecords/ModelCollection.cpp

${OBJECTDIR}/src/Subrecords/ScriptCollection.o: src/Subrecords/ScriptCollection.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Subrecords
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Subrecords/ScriptCollection.o src/Subrecords/ScriptCollection.cpp

${OBJECTDIR}/src/Subrecords/subEDID.o: src/Subrecords/subEDID.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/Subrecords
	${RM} "$@.d"
	$(COMPILE.cc) -g -D_DEVMESSAGES -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Subrecords/subEDID.o src/Subrecords/subEDID.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libesx-reader.a

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
