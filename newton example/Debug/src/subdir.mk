################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/newton\ example.cpp 

OBJS += \
./src/newton\ example.o 

CPP_DEPS += \
./src/newton\ example.d 


# Each subdirectory must supply rules for building sources it contributes
src/newton\ example.o: ../src/newton\ example.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/newton example.d" -MT"src/newton\ example.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


