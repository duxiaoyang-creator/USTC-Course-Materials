# Abstract:
#	Template makefile for building Simulink Desktop Real-Time compatible
#       real-time version of Simulink model using generated C or C++ code and
#       the built-in Clang compiler.
#
# 	This makefile is designed to be used with GNU Make (gmake) which is
#       located in matlabroot/bin/<arch>.
#
# 	Note that this template is automatically customized by the Simulink
#	Coder build procedure to create "<model>.mk"
#
#       The following defines (macro names) can be used to modify the behavior
#       of the build:
#	  OPT_OPTS       - Optimization options.
#	  OPTS           - User-specified compiler options.
#         CPP_OPTS       - User-specified C++ compiler options.
#	  USER_SRCS      - Additional user objects, such as files needed by
#			   S-functions.
#	  USER_INCLUDES  - Additional include paths (i.e.
#			   "USER_INCLUDES=include-path1;include-path2")
#                          Use a '/' as a file separator instead of '\'.
#
#       Consider using the "Build process" dialog in Code Generation
#       options page instead of trying to change OPT_OPTS here.
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.ProjectDirSuffix', see grt.tlc .
#
# !!! THIS FILE IS AUTO-GENERATED !!!
# Copyright 1994-2021 The MathWorks, Inc.



#------------------------ Macros read by make_rtw -----------------------------
#
# The following macros are read by the code generation build procedure:
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the code generation build procedure
#                    (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.
#

MAKECMD         = "C:/PROGRA~1/MATLAB/R2021b/bin/win64/gmake"
HOST            = ANY
BUILD           = yes
SYS_TARGET_FILE = sldrt.tlc
COMPILER_TOOL_CHAIN = default
MAKEFILE_FILESEP = /


#---------------------- Tokens expanded by make_rtw ---------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# code generation build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to were MATLAB is installed.
#  MATLAB_BIN          - Path to MATLAB executable.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous
#                        task (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  EXTMODE_TRANSPORT   - Name of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#
#  CC_LISTING          - yes (1) or no (0): Generate assembly listings
#  REBUILD_ALL         - yes (1) or no (0): Rebuild all files

MODEL                := shabishiyan
MODULES              := rt_matrx.c rt_printf.c rtGetInf.c rtGetNaN.c rt_nonfinite.c shabishiyan_data.c shabishiyan_tgtconn.c gts_getpos.c gts_initialize_m.c gts_setaccvel.c
MAKEFILE             := shabishiyan.mk
MATLAB_ROOT          := C:/PROGRA~1/MATLAB/R2021b
MATLAB_BIN           := C:/PROGRA~1/MATLAB/R2021b/bin
S_FUNCTIONS_LIB      := 
SOLVER               := 
NUMST                := 3
TID01EQ              := 1
NCSTATES             := 4
BUILDARGS            :=  EXTMODE_STATIC_ALLOC=0 EXTMODE_STATIC_ALLOC_SIZE=1000000 TMW_EXTMODE_TESTING=0 COMBINE_OUTPUT_UPDATE_FCNS=0 INCLUDE_MDL_TERMINATE_FCN=1 MULTI_INSTANCE_CODE=0 OPTS="-DTGTCONN -DEXT_MODE -DON_TARGET_WAIT_FOR_START=1 -DTID01EQ=1"
MULTITASKING         := 1
EXT_MODE             := 1
EXTMODE_TRANSPORT    := 0

MODELREFS            := 
TARGET_LANG_EXT      := c
TGT_FCN_LIB          := None
OPTIMIZATION_FLAGS   := -O4
ADDITIONAL_LDFLAGS   := 
DEFINES_CUSTOM       := 
DEFINES_OTHER        := -DHAVESTDIO
COMPILE_FLAGS_OTHER  := 

# Simulink Desktop Real-Time specific parameters
SLDRTDIR             := C:/PROGRA~1/MATLAB/R2021b/toolbox/sldrt
TARGETARCH           := win64
CC_LISTING           := 0
REBUILD_ALL          := 0

# ensure MATLAB_ROOT uses forward slashes on Windows - necessary for UNC paths
ifeq ($(OS),Windows_NT)
  override MATLAB_ROOT := $(subst \,/,$(MATLAB_ROOT))
endif

# if SLDRTDIR contains spaces, construct it from MATLAB_ROOT instead
ifneq ($(words $(SLDRTDIR)),1)
  SLDRTDIR := $(MATLAB_ROOT)/toolbox/sldrt
endif

# create a variable that contains a space
EMPTY :=
SPACE := $(EMPTY) $(EMPTY)

# compute RXEXT based on target architecture
RXEXT := $(if $(filter maci64,$(TARGETARCH)),rxm64,$(subst win,rxw,$(TARGETARCH)))

#--------------------------- Model and reference models -----------------------
#
MODELLIB                  := 
MODELREF_LINK_LIBS        := 
MODELREF_LINK_RSPFILE     := shabishiyan_ref.rsp
RELATIVE_PATH_TO_ANCHOR   := ..
MODELREF_TARGET_TYPE      := NONE


#------------------------------- OS-specific tools ----------------------------
#
ifeq ($(OS),Windows_NT)
  DELETEFILE = if exist $(1) del /f $(subst /,\,$(1))
  SHELL := cmd
else
  DELETEFILE = rm -f $(1)
endif


#------------------------ External mode ---------------------------------------
#
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS := -DEXT_MODE
endif


#------------------------------ Include Path -----------------------------
#
# MATLAB includes
REQ_INCLUDES := $(MATLAB_ROOT)/simulink/include;$(MATLAB_ROOT)/extern/include;$(MATLAB_ROOT)/rtw/c/src;$(MATLAB_ROOT)/rtw/c/src/ext_mode/common

# target-specific and compiler-specific includes
REQ_INCLUDES += ;$(MATLAB_ROOT)/toolbox/shared/can/src/scanutil;$(SLDRTDIR)/src

# additional includes
REQ_INCLUDES += ;C:/Users/admin/Desktop;C:/Users/admin/Desktop/shabishiyan_sldrt_win64;$(MATLAB_ROOT)/extern/include;$(MATLAB_ROOT)/simulink/include;$(MATLAB_ROOT)/rtw/c/src;$(MATLAB_ROOT)/rtw/c/src/ext_mode/common;$(MATLAB_ROOT)/toolbox/coder/rtiostream/src

INCLUDES := $(USER_INCLUDES);.;$(RELATIVE_PATH_TO_ANCHOR);$(REQ_INCLUDES)


#-------------------------------- Required compiler options ------------------
#
# compiler commands
include $(SLDRTDIR)/rtw/sldrtclang.mk
REQ_OPTS := $(subst ;,$(SPACE)-I,$(INCLUDES))

# linker commands
ifeq ($(CC_LISTING),1)
LINKLISTING = $(LLC) -filetype=asm -x86-asm-syntax=intel -o $(notdir $(basename $@)).asm $(notdir $(basename $@)).bc
endif


#-------------------------------- C Flags --------------------------------
#
OPT_OPTS ?= $(DEFAULT_OPT_OPTS)
COMMON_OPTS := $(REQ_OPTS) $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS) $(COMPILE_FLAGS_OTHER)

REQ_DEFINES := -DUSE_RTMODEL -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
               -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
               -DMT=$(MULTITASKING) $(DEFINES_CUSTOM) $(DEFINES_OTHER)

USER_INCLUDES ?=

# C++ language standard
CLANG_CPPSTD := $(subst ISO_C,-std=c,$(TGT_FCN_LIB)$(if $(filter ISO_C++,$(TGT_FCN_LIB)),03))

# form the complete compiler command
CC += $(CLANG_CC_OPTS) $(COMMON_OPTS) $(REQ_DEFINES)
CPP += $(CLANG_CPP_OPTS) $(CLANG_CPPSTD) $(CPP_OPTS) $(COMMON_OPTS) $(REQ_DEFINES)


#------------------------------- Source Files ---------------------------------
#
# standard target
ifeq ($(MODELREF_TARGET_TYPE),NONE)
  PRODUCT     := $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL).$(RXEXT)
  REQ_SRCS    := $(MODEL).$(TARGET_LANG_EXT) $(MODULES) \
                 sldrt_main.c rt_sim.c

ifeq ($(EXT_MODE),1)
  REQ_SRCS    += ext_svr.c updown_sldrt.c
endif

# model reference target
else
  PRODUCT  := $(MODELLIB)
  REQ_SRCS := $(MODULES)
endif

SRCS := $(REQ_SRCS) $(USER_SRCS)
SRCS += $(SOLVER)
OBJS := $(patsubst %.c,%.obj,$(patsubst %.cpp,%.obj,$(SRCS)))

#---------------------------- Additional Libraries ----------------------------
#
LIBS :=




#-------------------------- Rules ---------------------------------------
#
# decide what should get built
.DEFAULT_GOAL := $(if $(filter 1,$(REBUILD_ALL)), rebuild, $(PRODUCT))

# rule to rebuild everything unconditionally
.PHONY : rebuild
rebuild :
	$(MAKE) -B -f $(MAKEFILE) REBUILD_ALL=0

# libraries to link with the executable
ALLLIBS := $(strip $(LIBS) $(MODELREF_LINK_LIBS) $(S_FUNCTIONS_LIB))

# rules for linking the executable or modelref static library
ifeq ($(MODELREF_TARGET_TYPE),NONE)
$(PRODUCT) : $(OBJS) $(ALLLIBS)
	$(LINK) \
          -Bstatic \
	  -o $(notdir $(basename $@)).bc \
	  $(strip $(OBJS)) \
	  $(strip $(ALLLIBS)) \
	  $(SLDRTDIR)/lib/$(TARGETARCH)/imports.obj \
	  $(SLDRTDIR)/lib/$(TARGETARCH)/sldrtlib.lib
	$(LLC) -filetype=obj -o $@ $(notdir $(basename $@)).bc
	$(LINKLISTING)
	$(info ### Created Simulink Desktop Real-Time module $(notdir $@))
else
$(PRODUCT) : $(OBJS)
	@$(call DELETEFILE,$@)
	$(LIBTOOL) $@ $(OBJS)
	$(info ### Created static library $@)
endif

# path to additional sources
CPPSRCDIRS := $(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_ROOT)/simulink/src $(MATLAB_ROOT)/toolbox/gtbox/gts400pv $(MATLAB_ROOT)/toolbox/gtbox/gt400sv $(MATLAB_ROOT)/rtw/c/src $(MATLAB_ROOT)/simulink/src $(MATLAB_ROOT)/rtw/c/src/ext_mode/common 
CSRCDIRS := $(SLDRTDIR)/src $(MATLAB_ROOT)/rtw/c/src/ext_mode/common $(CPPSRCDIRS)
vpath %.c $(CSRCDIRS)
vpath %.cpp $(CPPSRCDIRS)

# object build macros
CC_CPP := $(if $(filter cpp,$(TARGET_LANG_EXT)),$(CPP),$(CC))
define BUILDOBJ
	$(info ### Compiling $<)
	$(1) -o "$@" "$<"
	$(CCLISTING)
endef

# rules for compiling objects
sldrt_main.obj : $(SLDRTDIR)/src/sldrt_main.c $(MAKEFILE)
	$(call BUILDOBJ, $(CC_CPP))

%.obj : %.c
	$(call BUILDOBJ, $(CC))

%.obj : %.cpp
	$(call BUILDOBJ, $(CPP))

# rules for building libraries



# batch compiler command to build objects for precompiled libraries
define CCBATCH
  $(CC) $(wordlist 1, 20, $1)
  $(if $(wordlist 21, 2147483647, $1), $(call CCBATCH, $(wordlist 21, 2147483647, $1)))
endef

# rules for precompiled libraries

