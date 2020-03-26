################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../../../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K1xx_RTM_3.0.0/platform/pal/src/can/can_pal.c" \

C_SRCS += \
C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K1xx_RTM_3.0.0/platform/pal/src/can/can_pal.c \

OBJS_OS_FORMAT += \
./SDK/platform/pal/src/can/can_pal.o \

C_DEPS_QUOTED += \
"./SDK/platform/pal/src/can/can_pal.d" \

OBJS += \
./SDK/platform/pal/src/can/can_pal.o \

OBJS_QUOTED += \
"./SDK/platform/pal/src/can/can_pal.o" \

C_DEPS += \
./SDK/platform/pal/src/can/can_pal.d \


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/pal/src/can/can_pal.o: C:/NXP/S32DS_ARM_v2018.R1/S32DS/S32SDK_S32K1xx_RTM_3.0.0/platform/pal/src/can/can_pal.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@SDK/platform/pal/src/can/can_pal.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "SDK/platform/pal/src/can/can_pal.o" "$<"
	@echo 'Finished building: $<'
	@echo ' '


