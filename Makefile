######################################
# target
######################################
TARGET = apm32f103cbt6

TARGET_DEFS = -DAPM32F10X_MD 

USER_SOURCES = \
	User/apm32f10x_int.c \
	User/main.c

USER_INCLUDES = -IUser

######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization for size
OPT = -Os


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
Library/Device/Geehy/APM32F10x/Source/system_apm32f10x.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_can.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_sci2c.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_misc.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_bakpr.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_dmc.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_gpio.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_tmr.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_rtc.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_rcm.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_emmc.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_sdio.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_dbgmcu.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_iwdt.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_usart.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_adc.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_wwdt.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_qspi.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_fmc.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_dac.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_eint.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_crc.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_dma.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_i2c.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_spi.c \
Library/APM32F10x_StdPeriphDriver/src/apm32f10x_pmu.c \
$(USER_SOURCES)

#Library/USB_Device_Lib/Driver/src/drv_usb_device.c \
#Library/USB_Device_Lib/Core_Device/Standard/src/usbd_init.c \
#Library/USB_Device_Lib/Core_Device/Standard/src/usbd_interrupt.c \
#Library/USB_Device_Lib/Core_Device/Standard/src/usbd_stdReq.c \
#Library/USB_Device_Lib/Core_Device/Standard/src/usbd_core.c \
#Library/USB_Device_Lib/Core_Device/Class/MSC/src/usbd_class_msc.c \
#Library/USB_Device_Lib/Core_Device/Class/MSC/src/usbd_msc_bot.c \
#Library/USB_Device_Lib/Core_Device/Class/MSC/src/usbd_msc_scsi.c \
#Library/USB_Device_Lib/Core_Device/Class/CDC/src/usbd_class_cdc.c \
#Library/USB_Device_Lib/Core_Device/Class/HID/src/usbd_class_hid.c \

# ASM sources
ASM_SOURCES = Library/Device/Geehy/APM32F10x/Source/gcc/startup_apm32f10x_md.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m3

# fpu
# NONE for Cortex-M0/M0+/M3

# float-abi


# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_STDPERIPH_DRIVER \
$(TARGET_DEFS)

# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-ILibrary/Device/Geehy/APM32F10x/Include \
-ILibrary/CMSIS/Include \
-ILibrary/APM32F10x_StdPeriphDriver/inc \
$(USER_INCLUDES)

#-ILibrary/USB_Device_Lib/Core_Device/Standard/inc \
#-ILibrary/USB_Device_Lib/Core_Device/Class/MSC/inc \
#-ILibrary/USB_Device_Lib/Core_Device/Class/CDC/inc \
#-ILibrary/USB_Device_Lib/Core_Device/Class/HID/inc \
#-ILibrary/USB_Device_Lib/Driver/inc \

# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = Library/apm32f103cbt6.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -u_printf_float -specs=nosys.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# program
#######################################
program:
	openocd -f /usr/share/openocd/scripts/interface/cmsis-dap.cfg -f /usr/share/openocd/scripts/target/stm32f1x.cfg -c "program build/$(TARGET).elf verify reset exit"

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)

#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
