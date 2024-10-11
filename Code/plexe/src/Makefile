#
# OMNeT++/OMNEST Makefile for $(LIB_PREFIX)plexe
#
# This file was generated with the command:
#  opp_makemake --make-so -f --deep -o plexe -O out -pPLEXE -KVEINS_PROJ=../../veins -DVEINS_IMPORT -I. -I$$\(VEINS_PROJ\)/src -I. -L$$\(VEINS_PROJ\)/src -lveins$$\(D\)
#

# Name of target to be created (-o option)
TARGET_DIR = .
TARGET_NAME = $(LIB_PREFIX)plexe$(D)
TARGET = $(TARGET_NAME)$(SHARED_LIB_SUFFIX)
TARGET_IMPLIB = $(TARGET_NAME)$(IMPLIB_SUFFIX)
TARGET_IMPDEF = $(TARGET_NAME)$(IMPDEF_SUFFIX)
TARGET_FILES = $(TARGET_DIR)/$(TARGET)

# C++ include paths (with -I)
INCLUDE_PATH = -I. -I$(VEINS_PROJ)/src -I.

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = $(LDFLAG_LIBPATH)$(VEINS_PROJ)/src  -lveins$(D)

# Output directory
PROJECT_OUTPUT_DIR = ../out
PROJECTRELATIVE_PATH = src
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = \
    $O/plexe/PlexeManager.o \
    $O/plexe/apps/BaseApp.o \
    $O/plexe/apps/GeneralPlatooningApp.o \
    $O/plexe/apps/SimplePlatooningApp.o \
    $O/plexe/driver/Veins11pRadioDriver.o \
    $O/plexe/maneuver/JoinAtBack.o \
    $O/plexe/maneuver/JoinManeuver.o \
    $O/plexe/maneuver/Maneuver.o \
    $O/plexe/maneuver/MergeAtBack.o \
    $O/plexe/mobility/CommandInterface.o \
    $O/plexe/mobility/SumoTrafficManager.o \
    $O/plexe/mobility/TestTrafficManager.o \
    $O/plexe/mobility/TraCIBaseTrafficManager.o \
    $O/plexe/protocols/BaseProtocol.o \
    $O/plexe/protocols/HumanInterferingProtocol.o \
    $O/plexe/protocols/SimplePlatooningBeaconing.o \
    $O/plexe/protocols/SlottedBeaconing.o \
    $O/plexe/scenarios/AccelerateAndBrakeScenario.o \
    $O/plexe/scenarios/AutoLaneChangeScenario.o \
    $O/plexe/scenarios/BaseScenario.o \
    $O/plexe/scenarios/BrakingScenario.o \
    $O/plexe/scenarios/JoinManeuverScenario.o \
    $O/plexe/scenarios/ManeuverScenario.o \
    $O/plexe/scenarios/MergeManeuverScenario.o \
    $O/plexe/scenarios/SimpleScenario.o \
    $O/plexe/scenarios/SinusoidalScenario.o \
    $O/plexe/traffic/JoinTrafficManager.o \
    $O/plexe/traffic/PlatoonsPlusHumanTraffic.o \
    $O/plexe/traffic/PlatoonsTrafficManager.o \
    $O/plexe/traffic/RingTrafficManager.o \
    $O/plexe/utilities/BasePositionHelper.o \
    $O/plexe/utilities/DynamicPositionManager.o \
    $O/plexe/utilities/PositionHelper.o \
    $O/plexe/messages/InterferingBeacon_m.o \
    $O/plexe/messages/JoinFormation_m.o \
    $O/plexe/messages/JoinFormationAck_m.o \
    $O/plexe/messages/JoinPlatoonRequest_m.o \
    $O/plexe/messages/JoinPlatoonResponse_m.o \
    $O/plexe/messages/ManeuverMessage_m.o \
    $O/plexe/messages/MergePlatoonRequest_m.o \
    $O/plexe/messages/MoveToPosition_m.o \
    $O/plexe/messages/MoveToPositionAck_m.o \
    $O/plexe/messages/PlatooningBeacon_m.o \
    $O/plexe/messages/PlexeInterfaceControlInfo_m.o \
    $O/plexe/messages/UpdatePlatoonData_m.o \
    $O/plexe/messages/UpdatePlatoonFormation_m.o \
    $O/plexe/messages/UpdatePlatoonFormationAck_m.o

# Message files
MSGFILES = \
    plexe/messages/InterferingBeacon.msg \
    plexe/messages/JoinFormation.msg \
    plexe/messages/JoinFormationAck.msg \
    plexe/messages/JoinPlatoonRequest.msg \
    plexe/messages/JoinPlatoonResponse.msg \
    plexe/messages/ManeuverMessage.msg \
    plexe/messages/MergePlatoonRequest.msg \
    plexe/messages/MoveToPosition.msg \
    plexe/messages/MoveToPositionAck.msg \
    plexe/messages/PlatooningBeacon.msg \
    plexe/messages/PlexeInterfaceControlInfo.msg \
    plexe/messages/UpdatePlatoonData.msg \
    plexe/messages/UpdatePlatoonFormation.msg \
    plexe/messages/UpdatePlatoonFormationAck.msg

# SM files
SMFILES =

# Other makefile variables (-K)
VEINS_PROJ=../../veins

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
CONFIGFILE = $(shell opp_configfilepath)
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIBS = -loppenvir$D $(KERNEL_LIBS) $(SYS_LIBS)
ifneq ($(PLATFORM),win32)
LIBS += -Wl,-rpath,$(abspath $(VEINS_PROJ)/src)
endif

COPTS = $(CFLAGS) $(IMPORT_DEFINES) -DVEINS_IMPORT -DPLEXE_EXPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH) -PPLEXE_API
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE (if COPTS has changed since last build)
# and make the object files depend on it
COPTS_FILE = $O/.last-copts
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
  $(shell $(MKPATH) "$O")
  $(file >$(COPTS_FILE),$(COPTS))
endif

# On Windows, the target has additional file(s). An import lib and an optional debug symbol file is created too.
ifeq ($(PLATFORM),win32)
  TARGET_FILES+= $(TARGET_DIR)/$(TARGET_IMPLIB)
  LDFLAGS+= $(LDFLAG_IMPLIB)$O/$(TARGET_IMPLIB)
  ifeq ($(TOOLCHAIN_NAME),clang-msabi)
    ifeq ($(MODE),debug)
      TARGET_FILES+=$(TARGET_DIR)/$(TARGET_NAME).pdb
    endif
  else
    TARGET_FILES+= $(TARGET_DIR)/$(TARGET_IMPDEF)
    LDFLAGS+= $(LDFLAG_IMPDEF)$O/$(TARGET_IMPDEF)
  endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
-include makefrag

#------------------------------------------------------------------------------

# Main target
all: $(TARGET_FILES)

$(TARGET_DIR)/% :: $O/%
	@mkdir -p $(TARGET_DIR)
	$(Q)$(LN) $< $@
ifeq ($(TOOLCHAIN_NAME),clang-msabi)
	-$(Q)-$(LN) $(<:%.dll=%.lib) $(@:%.dll=%.lib) 2>/dev/null

$O/$(TARGET_NAME).pdb: $O/$(TARGET)
endif

$O/$(TARGET) $O/$(TARGET_IMPDEF) $O/$(TARGET_IMPLIB) &: $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile $(CONFIGFILE)
	@$(MKPATH) $O
	@echo Creating shared library: $@
	$(Q)$(SHLIB_LD) -o $O/$(TARGET) $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS) $(LDFLAGS)
	$(Q)$(SHLIB_POSTPROCESS) $O/$(TARGET)
ifeq ($(PLATFORM),win32)
	$(Q)llvm-ar d $O/$(TARGET_IMPLIB) $(TARGET) # WORKAROUND: throw away the first file from the archive to make the LLD generated import lib valid
endif

.PHONY: all clean cleanall depend msgheaders smheaders

# disabling all implicit rules
.SUFFIXES :
.PRECIOUS : %_m.h %_m.cc

$O/%.o: %.cc $(COPTS_FILE) | msgheaders smheaders
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc -MD -MP -MF $O/$(basename $<)_m.h.d $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning $(TARGET)
	$(Q)-rm -rf $O
	$(Q)-rm -f $(TARGET_FILES)
	$(Q)-rm -f $(call opp_rwildcard, . , *_m.cc *_m.h *_sm.cc *_sm.h)

cleanall:
	$(Q)$(CLEANALL_COMMAND)
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

help:
	@echo "$$HELP_SYNOPSYS"
	@echo "$$HELP_TARGETS"
	@echo "$$HELP_VARIABLES"
	@echo "$$HELP_EXAMPLES"

# include all dependencies
-include $(OBJS:%=%.d) $(MSGFILES:%.msg=$O/%_m.h.d)
