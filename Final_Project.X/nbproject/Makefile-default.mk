#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ds1631.c i2c.c main.c trigger.c uart.c lcd.c my_rgbLED.c my_buttons.c ui.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ds1631.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/main.o ${OBJECTDIR}/trigger.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/my_rgbLED.o ${OBJECTDIR}/my_buttons.o ${OBJECTDIR}/ui.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ds1631.o.d ${OBJECTDIR}/i2c.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/trigger.o.d ${OBJECTDIR}/uart.o.d ${OBJECTDIR}/lcd.o.d ${OBJECTDIR}/my_rgbLED.o.d ${OBJECTDIR}/my_buttons.o.d ${OBJECTDIR}/ui.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ds1631.o ${OBJECTDIR}/i2c.o ${OBJECTDIR}/main.o ${OBJECTDIR}/trigger.o ${OBJECTDIR}/uart.o ${OBJECTDIR}/lcd.o ${OBJECTDIR}/my_rgbLED.o ${OBJECTDIR}/my_buttons.o ${OBJECTDIR}/ui.o

# Source Files
SOURCEFILES=ds1631.c i2c.c main.c trigger.c uart.c lcd.c my_rgbLED.c my_buttons.c ui.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24EP128GP202
MP_LINKER_FILE_OPTION=,--script=p24EP128GP202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ds1631.o: ds1631.c  .generated_files/flags/default/3358d58166a78f36d3854629436209f10aac402a .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ds1631.o.d 
	@${RM} ${OBJECTDIR}/ds1631.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ds1631.c  -o ${OBJECTDIR}/ds1631.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ds1631.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2c.o: i2c.c  .generated_files/flags/default/1535aef1a2430e84b281ccf8e8e0455242a3b57d .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c.c  -o ${OBJECTDIR}/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2c.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/836311f05169aa7a996b227d1ce50f98a1130284 .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/trigger.o: trigger.c  .generated_files/flags/default/c353ab2f8f5b958aa575235340abba33278d43df .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/trigger.o.d 
	@${RM} ${OBJECTDIR}/trigger.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  trigger.c  -o ${OBJECTDIR}/trigger.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/trigger.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/ec612b1476753860858d44bbd7c0f0fc0a6c28ad .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart.c  -o ${OBJECTDIR}/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd.o: lcd.c  .generated_files/flags/default/465473f2966f11b8755c7612ca78c6b144fe1558 .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd.c  -o ${OBJECTDIR}/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/my_rgbLED.o: my_rgbLED.c  .generated_files/flags/default/f1e988da3c85624447e5aabcfb7dfb19b2cd3ef3 .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/my_rgbLED.o.d 
	@${RM} ${OBJECTDIR}/my_rgbLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  my_rgbLED.c  -o ${OBJECTDIR}/my_rgbLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/my_rgbLED.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/my_buttons.o: my_buttons.c  .generated_files/flags/default/f18b95e00453cc7edb94f33694cdda9730eef499 .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/my_buttons.o.d 
	@${RM} ${OBJECTDIR}/my_buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  my_buttons.c  -o ${OBJECTDIR}/my_buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/my_buttons.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ui.o: ui.c  .generated_files/flags/default/8256c94e117364e89e96adc7c9df9a0afbb5c4e8 .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ui.o.d 
	@${RM} ${OBJECTDIR}/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ui.c  -o ${OBJECTDIR}/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ui.o.d"      -g -D__DEBUG   -mno-eds-warn  -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
else
${OBJECTDIR}/ds1631.o: ds1631.c  .generated_files/flags/default/e8a85c2dca581cc16bdf6a38055d76539661353b .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ds1631.o.d 
	@${RM} ${OBJECTDIR}/ds1631.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ds1631.c  -o ${OBJECTDIR}/ds1631.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ds1631.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/i2c.o: i2c.c  .generated_files/flags/default/594ef3e75575b506cdeb213e05e52ed3850ba1cb .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/i2c.o.d 
	@${RM} ${OBJECTDIR}/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  i2c.c  -o ${OBJECTDIR}/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/i2c.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/8030728b8535257b5977cd73c4a677329383563b .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  main.c  -o ${OBJECTDIR}/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/trigger.o: trigger.c  .generated_files/flags/default/a718077196dedc02bdcf34b3d0b834cdac30aa9b .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/trigger.o.d 
	@${RM} ${OBJECTDIR}/trigger.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  trigger.c  -o ${OBJECTDIR}/trigger.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/trigger.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/uart.o: uart.c  .generated_files/flags/default/1516a17e30667f33d7697082efc5558181d94aed .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/uart.o.d 
	@${RM} ${OBJECTDIR}/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  uart.c  -o ${OBJECTDIR}/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/uart.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/lcd.o: lcd.c  .generated_files/flags/default/ce95a180b0fca23724aebb78bbc5a01e7bb4f4a9 .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/lcd.o.d 
	@${RM} ${OBJECTDIR}/lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  lcd.c  -o ${OBJECTDIR}/lcd.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/lcd.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/my_rgbLED.o: my_rgbLED.c  .generated_files/flags/default/de58169cf865a4bd2a92487606879404b2c4f3e1 .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/my_rgbLED.o.d 
	@${RM} ${OBJECTDIR}/my_rgbLED.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  my_rgbLED.c  -o ${OBJECTDIR}/my_rgbLED.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/my_rgbLED.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/my_buttons.o: my_buttons.c  .generated_files/flags/default/6743fcd4c4a91614b3a415e373719b99928b3788 .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/my_buttons.o.d 
	@${RM} ${OBJECTDIR}/my_buttons.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  my_buttons.c  -o ${OBJECTDIR}/my_buttons.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/my_buttons.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
${OBJECTDIR}/ui.o: ui.c  .generated_files/flags/default/a38b914dc7580ca011d2590a2852f84fb7190ec2 .generated_files/flags/default/ea09e513fe459e3ee4329c12b42bb02e1cc832c2
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ui.o.d 
	@${RM} ${OBJECTDIR}/ui.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ui.c  -o ${OBJECTDIR}/ui.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/ui.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O0 -msmart-io=1 -Wall -msfr-warn=off    -mdfp="${DFP_DIR}/xc16"
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG=__DEBUG   -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D__DEBUG=__DEBUG,,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	
else
${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o ${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,${DISTDIR}/memoryfile.xml$(MP_EXTRA_LD_POST)  -mdfp="${DFP_DIR}/xc16" 
	${MP_CC_DIR}\\xc16-bin2hex ${DISTDIR}/Final_Project.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf   -mdfp="${DFP_DIR}/xc16" 
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
