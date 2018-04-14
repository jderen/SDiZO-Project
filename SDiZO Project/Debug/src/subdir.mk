################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Drzewo.cpp \
../src/DrzewoElement.cpp \
../src/Kopiec.cpp \
../src/Lista.cpp \
../src/ListaElement.cpp \
../src/MierzenieCzasu.cpp \
../src/SDiZO\ Project.cpp \
../src/Tablica.cpp \
../src/Testowanie.cpp 

OBJS += \
./src/Drzewo.o \
./src/DrzewoElement.o \
./src/Kopiec.o \
./src/Lista.o \
./src/ListaElement.o \
./src/MierzenieCzasu.o \
./src/SDiZO\ Project.o \
./src/Tablica.o \
./src/Testowanie.o 

CPP_DEPS += \
./src/Drzewo.d \
./src/DrzewoElement.d \
./src/Kopiec.d \
./src/Lista.d \
./src/ListaElement.d \
./src/MierzenieCzasu.d \
./src/SDiZO\ Project.d \
./src/Tablica.d \
./src/Testowanie.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/SDiZO\ Project.o: ../src/SDiZO\ Project.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/SDiZO Project.d" -MT"src/SDiZO\ Project.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


