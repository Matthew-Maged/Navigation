################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP_program.c \
../DCM_program.c \
../DIO_program.c \
../IR_program.c \
../PORT_program.c \
../TIMER0_program.c \
../TIMER2_program.c \
../main.c 

OBJS += \
./APP_program.o \
./DCM_program.o \
./DIO_program.o \
./IR_program.o \
./PORT_program.o \
./TIMER0_program.o \
./TIMER2_program.o \
./main.o 

C_DEPS += \
./APP_program.d \
./DCM_program.d \
./DIO_program.d \
./IR_program.d \
./PORT_program.d \
./TIMER0_program.d \
./TIMER2_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


