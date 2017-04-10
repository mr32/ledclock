CC = avr-gcc
MMCU = atmega328p
FCPU = 16000000UL
CFLAGS = -c -o 


ledclock: main.o
	$(CC) -mmcu=$(MMCU) main.o -o main
	avr-objcopy -O ihex -R .eeprom main main.hex

main.o: main.c
	$(CC) -Os -DF_CPU=$(FCPU) -mmcu=$(MMCU) $(CFLAGS) main.o main.c

upload:
	sudo avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:main.hex

clean:
	rm main.o main main.hex
