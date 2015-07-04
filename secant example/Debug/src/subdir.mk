################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/secant\ example.cpp 

OBJS += \
./src/secant\ example.o 

CPP_DEPS += \
./src/secant\ example.d 


# Each subdirectory must supply rules for building sources it contributes
src/secant\ example.o: ../src/secant\ example.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/secant example.d" -MT"src/secant\ example.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


