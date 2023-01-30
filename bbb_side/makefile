BBB-GCC := /home/omer/Desktop/Embedded_Linux/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc
FLAGS := -Wall -g -pedantic -o

prog: main.o uart.o gpio.o
	${BBB-GCC} ${FLAGS} prog main.o uart.o gpio.o

main.o: main.c 
	${BBB-GCC} -c ${FLAGS} main.o main.c

uart.o: uart.c
	${BBB-GCC} -c ${FLAGS} uart.o uart.c

gpio.o: gpio.c
	${BBB-GCC} -c ${FLAGS} gpio.o gpio.c

clean:
	rm *.o prog
