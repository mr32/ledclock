CC = avr-gcc
MMCU = atmega328p
FCPU = 16000000UL
CFLAGS = -Os -DF_CPU=$(FCPU) -mmcu=$(MMCU) -c -o 


ledclock: main.o uart.o rbuf.o time.o
	$(CC) -mmcu=$(MMCU) main.o uart.o rbuf.o time.o -o main
	avr-objcopy -O ihex -R .eeprom main main.hex

main.o: main.c main.h
	$(CC) $(CFLAGS) main.o main.c

uart.o: uart.c uart.h
	$(CC) $(CFLAGS) uart.o uart.c

rbuf.o: rbuf.c rbuf.h 
	$(CC) $(CFLAGS) rbuf.o rbuf.c

time.o: time.c time.h
	$(CC) $(CFLAGS) time.o time.c

upload:
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex

clean:
	rm main main.hex main.o uart.o rbuf.o time.o
