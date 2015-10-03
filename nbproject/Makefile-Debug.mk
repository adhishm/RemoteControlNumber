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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1348093554/Counter.o \
	${OBJECTDIR}/_ext/1348093554/SampleListener.o \
	${OBJECTDIR}/main.o


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
LDLIBSOPTIONS=-L/home/adhish/Documents/leap/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/lib/x64/ -lLeap -dynamic

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/remotecontrolnumber

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/remotecontrolnumber: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/remotecontrolnumber ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/1348093554/Counter.o: /home/adhish/Documents/leap/Sources/RemoteControlNumber/Counter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1348093554
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/adhish/Documents/leap/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1348093554/Counter.o /home/adhish/Documents/leap/Sources/RemoteControlNumber/Counter.cpp

${OBJECTDIR}/_ext/1348093554/SampleListener.o: /home/adhish/Documents/leap/Sources/RemoteControlNumber/SampleListener.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1348093554
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/adhish/Documents/leap/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/1348093554/SampleListener.o /home/adhish/Documents/leap/Sources/RemoteControlNumber/SampleListener.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/home/adhish/Documents/leap/LeapDeveloperKit_2.3.1+31549_linux/LeapSDK/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/remotecontrolnumber

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
