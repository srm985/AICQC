################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../src/ \
../src/ASF/ \
../src/ASF/common/ \
../src/ASF/common/boards/ \
../src/ASF/common/utils/ \
../src/ASF/common/utils/interrupt/ \
../src/ASF/common/utils/make/ \
../src/ASF/mega/ \
../src/ASF/mega/boards/ \
../src/ASF/mega/boards/stk600/ \
../src/ASF/mega/boards/stk600/rcx_x/ \
../src/ASF/mega/utils/ \
../src/ASF/mega/utils/assembler/ \
../src/ASF/mega/utils/preprocessor/ \
../src/config/ \
../src/i2chw/


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../src/I2C.c \
../src/LCD_Disp.c \
../src/LED_Disp.c \
../src/main.c \
../src/ASF/mega/boards/stk600/rcx_x/init.c \
../src/Sharp_IR.c \
../src/UART.c \
../src/Ultrasonic.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
src/I2C.o \
src/LCD_Disp.o \
src/LED_Disp.o \
src/main.o \
src/ASF/mega/boards/stk600/rcx_x/init.o \
src/Sharp_IR.o \
src/UART.o \
src/Ultrasonic.o

OBJS_AS_ARGS +=  \
src/I2C.o \
src/LCD_Disp.o \
src/LED_Disp.o \
src/main.o \
src/ASF/mega/boards/stk600/rcx_x/init.o \
src/Sharp_IR.o \
src/UART.o \
src/Ultrasonic.o

C_DEPS +=  \
src/I2C.d \
src/LCD_Disp.d \
src/LED_Disp.d \
src/main.d \
src/ASF/mega/boards/stk600/rcx_x/init.d \
src/Sharp_IR.d \
src/UART.d \
src/Ultrasonic.d

C_DEPS_AS_ARGS +=  \
src/I2C.d \
src/LCD_Disp.d \
src/LED_Disp.d \
src/main.d \
src/ASF/mega/boards/stk600/rcx_x/init.d \
src/Sharp_IR.d \
src/UART.d \
src/Ultrasonic.d

OUTPUT_FILE_PATH +=paska.elf

OUTPUT_FILE_PATH_AS_ARGS +=paska.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

# AVR32/GNU C Compiler

















src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 3.4.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -DBOARD=STK600_MEGA  -I"../src" -I"../src/ASF/common/boards" -I"../src/ASF/common/utils" -I"../src/ASF/mega/utils" -I"../src/ASF/mega/utils/preprocessor" -I"../src/config"  -Os -fdata-sections -ffunction-sections -fdata-sections -g3 -Wall -mmcu=atmega32 -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<"
	@echo Finished building: $<
	

src/ASF/mega/boards/stk600/rcx_x/%.o: ../src/ASF/mega/boards/stk600/rcx_x/%.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 3.4.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -DBOARD=STK600_MEGA  -I"../src" -I"../src/ASF/common/boards" -I"../src/ASF/common/utils" -I"../src/ASF/mega/utils" -I"../src/ASF/mega/utils/preprocessor" -I"../src/config"  -Os -fdata-sections -ffunction-sections -fdata-sections -g3 -Wall -mmcu=atmega32 -c -std=gnu99 -fno-strict-aliasing -Wstrict-prototypes -Wmissing-prototypes -Werror-implicit-function-declaration -Wpointer-arith -mrelax -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<"
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 3.4.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="paska.map" -Wl,--start-group  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega32 -Wl,--relax 
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "paska.elf" "paska.hex"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "paska.elf" "paska.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "paska.elf" > "paska.lss"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature  "paska.elf" "paska.srec"
	"C:\Program Files (x86)\Atmel\Atmel Toolchain\AVR8 GCC\Native\3.4.2.1002\avr8-gnu-toolchain\bin\avr-size.exe" "paska.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "paska.elf" "paska.a" "paska.hex" "paska.lss" "paska.eep" "paska.map" "paska.srec"
	