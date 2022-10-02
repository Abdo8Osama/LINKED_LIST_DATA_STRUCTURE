################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
FLASH_IMAGE += \
LINKED_LIST_DATA_STRUCTURE.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: LINKED_LIST_DATA_STRUCTURE.elf secondary-outputs

# Tool invocations
LINKED_LIST_DATA_STRUCTURE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LINKED_LIST_DATA_STRUCTURE.map -mmcu=atmega32 -o "LINKED_LIST_DATA_STRUCTURE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LINKED_LIST_DATA_STRUCTURE.hex: LINKED_LIST_DATA_STRUCTURE.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LINKED_LIST_DATA_STRUCTURE.elf  "LINKED_LIST_DATA_STRUCTURE.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LINKED_LIST_DATA_STRUCTURE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LINKED_LIST_DATA_STRUCTURE.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: LINKED_LIST_DATA_STRUCTURE.elf
	@echo 'Invoking: AVRDude'
	F:\ITI Embedded Systems\interfacing\IMT Data\01- SDK\IMT_SDK_Win_64\WinAVR\bin\avrdude -pm32 -cusbasp -Uflash:w:LINKED_LIST_DATA_STRUCTURE.hex:a
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(C_DEPS) LINKED_LIST_DATA_STRUCTURE.elf
	-@echo ' '

secondary-outputs: $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
