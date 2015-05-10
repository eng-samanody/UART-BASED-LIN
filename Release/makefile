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
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
UART_BASED_LIN_MASTER.lss \

FLASH_IMAGE += \
UART_BASED_LIN_MASTER.hex \

EEPROM_IMAGE += \
UART_BASED_LIN_MASTER.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: UART_BASED_LIN_MASTER.elf secondary-outputs

# Tool invocations
UART_BASED_LIN_MASTER.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,UART_BASED_LIN_MASTER.map -mmcu=atmega16 -o "UART_BASED_LIN_MASTER.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UART_BASED_LIN_MASTER.lss: UART_BASED_LIN_MASTER.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S UART_BASED_LIN_MASTER.elf  >"UART_BASED_LIN_MASTER.lss"
	@echo 'Finished building: $@'
	@echo ' '

UART_BASED_LIN_MASTER.hex: UART_BASED_LIN_MASTER.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex UART_BASED_LIN_MASTER.elf  "UART_BASED_LIN_MASTER.hex"
	@echo 'Finished building: $@'
	@echo ' '

UART_BASED_LIN_MASTER.eep: UART_BASED_LIN_MASTER.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex UART_BASED_LIN_MASTER.elf  "UART_BASED_LIN_MASTER.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: UART_BASED_LIN_MASTER.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 UART_BASED_LIN_MASTER.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(FLASH_IMAGE)$(ELFS)$(LSS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS) UART_BASED_LIN_MASTER.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
