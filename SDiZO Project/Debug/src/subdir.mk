################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/SDiZO\ Project.cpp \
../src/Tablica.cpp 

OBJS += \
./src/SDiZO\ Project.o \
./src/Tablica.o 

CPP_DEPS += \
./src/SDiZO\ Project.d \
./src/Tablica.d 


# Each subdirectory must supply rules for building sources it contributes
src/SDiZO\ Project.o: ../src/SDiZO\ Project.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/SDiZO Project.d" -MT"src/SDiZO\ Project.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

