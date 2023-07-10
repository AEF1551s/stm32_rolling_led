################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/syscalls.c \
../Src/sysmem.c 

CPP_SRCS += \
../Src/main.cpp 

C_DEPS += \
./Src/syscalls.d \
./Src/sysmem.d 

OBJS += \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

CPP_DEPS += \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DSTM32F410RBTx -DSTM32 -DSTM32F4 -c -I../Inc -I"/home/roboros/STM32CubeIDE/stm32_workspace/rolling_led/Drivers/CMSIS/Include" -I"/home/roboros/STM32CubeIDE/stm32_workspace/rolling_led/Drivers/CMSIS/Device" -I"/home/roboros/STM32CubeIDE/stm32_workspace/rolling_led/Drivers" -I"/home/roboros/STM32CubeIDE/stm32_workspace/rolling_led/Drivers/CMSIS" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F410RBTx -DSTM32 -DSTM32F4 -c -I../Inc -I"/home/roboros/STM32CubeIDE/stm32_workspace/rolling_led/Drivers/CMSIS/Device" -I"/home/roboros/STM32CubeIDE/stm32_workspace/rolling_led/Drivers/CMSIS/Include" -I"/home/roboros/STM32CubeIDE/stm32_workspace/rolling_led/Drivers" -I"/home/roboros/STM32CubeIDE/stm32_workspace/rolling_led/Drivers/CMSIS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

