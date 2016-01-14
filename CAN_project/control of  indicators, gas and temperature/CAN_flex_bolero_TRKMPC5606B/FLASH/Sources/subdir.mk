################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Can.c" \
"../Sources/Can_Cfg.c" \
"../Sources/Can_Manager.c" \
"../Sources/Exceptions.c" \
"../Sources/GPIO.c" \
"../Sources/IntcInterrupts.c" \
"../Sources/MemAlloc.c" \
"../Sources/MemAlloc_Cfg.c" \
"../Sources/PIT.c" \
"../Sources/SchM.c" \
"../Sources/SchM_Cfg.c" \
"../Sources/SchM_Tasks.c" \
"../Sources/application.c" \
"../Sources/bspimain.c" \
"../Sources/dummy.c" \
"../Sources/ivor_branch_table.c" \
"../Sources/main.c" \
"../Sources/sysinit.c" \

C_SRCS += \
../Sources/Can.c \
../Sources/Can_Cfg.c \
../Sources/Can_Manager.c \
../Sources/Exceptions.c \
../Sources/GPIO.c \
../Sources/IntcInterrupts.c \
../Sources/MemAlloc.c \
../Sources/MemAlloc_Cfg.c \
../Sources/PIT.c \
../Sources/SchM.c \
../Sources/SchM_Cfg.c \
../Sources/SchM_Tasks.c \
../Sources/application.c \
../Sources/bspimain.c \
../Sources/dummy.c \
../Sources/ivor_branch_table.c \
../Sources/main.c \
../Sources/sysinit.c \

OBJS += \
./Sources/Can_c.obj \
./Sources/Can_Cfg_c.obj \
./Sources/Can_Manager_c.obj \
./Sources/Exceptions_c.obj \
./Sources/GPIO_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/MemAlloc_c.obj \
./Sources/MemAlloc_Cfg_c.obj \
./Sources/PIT_c.obj \
./Sources/SchM_c.obj \
./Sources/SchM_Cfg_c.obj \
./Sources/SchM_Tasks_c.obj \
./Sources/application_c.obj \
./Sources/bspimain_c.obj \
./Sources/dummy_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \
./Sources/sysinit_c.obj \

OBJS_QUOTED += \
"./Sources/Can_c.obj" \
"./Sources/Can_Cfg_c.obj" \
"./Sources/Can_Manager_c.obj" \
"./Sources/Exceptions_c.obj" \
"./Sources/GPIO_c.obj" \
"./Sources/IntcInterrupts_c.obj" \
"./Sources/MemAlloc_c.obj" \
"./Sources/MemAlloc_Cfg_c.obj" \
"./Sources/PIT_c.obj" \
"./Sources/SchM_c.obj" \
"./Sources/SchM_Cfg_c.obj" \
"./Sources/SchM_Tasks_c.obj" \
"./Sources/application_c.obj" \
"./Sources/bspimain_c.obj" \
"./Sources/dummy_c.obj" \
"./Sources/ivor_branch_table_c.obj" \
"./Sources/main_c.obj" \
"./Sources/sysinit_c.obj" \

C_DEPS += \
./Sources/Can_c.d \
./Sources/Can_Cfg_c.d \
./Sources/Can_Manager_c.d \
./Sources/Exceptions_c.d \
./Sources/GPIO_c.d \
./Sources/IntcInterrupts_c.d \
./Sources/MemAlloc_c.d \
./Sources/MemAlloc_Cfg_c.d \
./Sources/PIT_c.d \
./Sources/SchM_c.d \
./Sources/SchM_Cfg_c.d \
./Sources/SchM_Tasks_c.d \
./Sources/application_c.d \
./Sources/bspimain_c.d \
./Sources/dummy_c.d \
./Sources/ivor_branch_table_c.d \
./Sources/main_c.d \
./Sources/sysinit_c.d \

OBJS_OS_FORMAT += \
./Sources/Can_c.obj \
./Sources/Can_Cfg_c.obj \
./Sources/Can_Manager_c.obj \
./Sources/Exceptions_c.obj \
./Sources/GPIO_c.obj \
./Sources/IntcInterrupts_c.obj \
./Sources/MemAlloc_c.obj \
./Sources/MemAlloc_Cfg_c.obj \
./Sources/PIT_c.obj \
./Sources/SchM_c.obj \
./Sources/SchM_Cfg_c.obj \
./Sources/SchM_Tasks_c.obj \
./Sources/application_c.obj \
./Sources/bspimain_c.obj \
./Sources/dummy_c.obj \
./Sources/ivor_branch_table_c.obj \
./Sources/main_c.obj \
./Sources/sysinit_c.obj \

C_DEPS_QUOTED += \
"./Sources/Can_c.d" \
"./Sources/Can_Cfg_c.d" \
"./Sources/Can_Manager_c.d" \
"./Sources/Exceptions_c.d" \
"./Sources/GPIO_c.d" \
"./Sources/IntcInterrupts_c.d" \
"./Sources/MemAlloc_c.d" \
"./Sources/MemAlloc_Cfg_c.d" \
"./Sources/PIT_c.d" \
"./Sources/SchM_c.d" \
"./Sources/SchM_Cfg_c.d" \
"./Sources/SchM_Tasks_c.d" \
"./Sources/application_c.d" \
"./Sources/bspimain_c.d" \
"./Sources/dummy_c.d" \
"./Sources/ivor_branch_table_c.d" \
"./Sources/main_c.d" \
"./Sources/sysinit_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Can_c.obj: ../Sources/Can.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Can.args" -o "Sources/Can_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/Can_Cfg_c.obj: ../Sources/Can_Cfg.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Can_Cfg.args" -o "Sources/Can_Cfg_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Can_Manager_c.obj: ../Sources/Can_Manager.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Can_Manager.args" -o "Sources/Can_Manager_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Exceptions_c.obj: ../Sources/Exceptions.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Exceptions.args" -o "Sources/Exceptions_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/GPIO_c.obj: ../Sources/GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/GPIO.args" -o "Sources/GPIO_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/IntcInterrupts_c.obj: ../Sources/IntcInterrupts.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/IntcInterrupts.args" -o "Sources/IntcInterrupts_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/MemAlloc_c.obj: ../Sources/MemAlloc.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MemAlloc.args" -o "Sources/MemAlloc_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/MemAlloc_Cfg_c.obj: ../Sources/MemAlloc_Cfg.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MemAlloc_Cfg.args" -o "Sources/MemAlloc_Cfg_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/PIT_c.obj: ../Sources/PIT.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/PIT.args" -o "Sources/PIT_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SchM_c.obj: ../Sources/SchM.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SchM.args" -o "Sources/SchM_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SchM_Cfg_c.obj: ../Sources/SchM_Cfg.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SchM_Cfg.args" -o "Sources/SchM_Cfg_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/SchM_Tasks_c.obj: ../Sources/SchM_Tasks.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/SchM_Tasks.args" -o "Sources/SchM_Tasks_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/application_c.obj: ../Sources/application.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/application.args" -o "Sources/application_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/bspimain_c.obj: ../Sources/bspimain.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/bspimain.args" -o "Sources/bspimain_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/dummy_c.obj: ../Sources/dummy.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/dummy.args" -o "Sources/dummy_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/ivor_branch_table_c.obj: ../Sources/ivor_branch_table.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/ivor_branch_table.args" -o "Sources/ivor_branch_table_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/main.args" -o "Sources/main_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/sysinit_c.obj: ../Sources/sysinit.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/sysinit.args" -o "Sources/sysinit_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


