CC = avr-gcc
MMCU = atmega328p
FCPU = 16000000UL
CFLAGS = -Os -DF_CPU=$(FCPU) -mmcu=$(MMCU) -c -o 


ledclock: main.o gpio.o uart.o rbuf.o time.o display.o shiftreg.o
	$(CC) -mmcu=$(MMCU) main.o gpio.o uart.o rbuf.o time.o display.o shiftreg.o -o main
	avr-objcopy -O ihex -R .eeprom main main.hex

main.o: main.c main.h
	$(CC) $(CFLAGS) main.o main.c

gpio.o: gpio.c gpio.h
	$(CC) $(CFLAGS) gpio.o gpio.c

uart.o: uart.c uart.h
	$(CC) $(CFLAGS) uart.o uart.c

rbuf.o: rbuf.c rbuf.h 
	$(CC) $(CFLAGS) rbuf.o rbuf.c

time.o: time.c time.h
	$(CC) $(CFLAGS) time.o time.c

display.o: display.c display.h
	$(CC) $(CFLAGS) display.o display.c

shiftreg.o: shiftreg.c shiftreg.h
	$(CC) $(CFLAGS) shiftreg.o shiftreg.c

upload:
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex

clean:
	rm main main.hex main.o gpio.o uart.o rbuf.o time.o display.o shiftreg.o
