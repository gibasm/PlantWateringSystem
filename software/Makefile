# --- MCU ---
MCU=atmega88pa

# --- AVRDUDE ---
AVRDUDE_MCU=m88p
PROG=usbasp

# -- COMPILER AND LINKER OPTIONS ---
CC=avr-gcc
CFLAGS=-Wall -mmcu=$(MCU)

OC=avr-objcopy
OFLAGS=-O ihex

# --- FILES ---
SOURCE_FILES=src/*.c
OUT_NAME=main.out
HEX_NAME=main.hex

# --- BUILD THE SOURCE ---
all:
	$(CC) $(CFLAGS) $(SOURCE_FILES) -o main.out
	$(OC) $(OFLAGS) $(OUT_NAME) $(HEX_NAME)	

# --- CHECK CONNECTIONS ---
check:
	avrdude -c $(PROG) -p $(AVRDUDE_MCU)

# --- WRITE THE HEX FILE TO THE FLASH MEMORY ---
burn:
	avrdude -c $(PROG) -p $(AVRDUDE_MCU) -U flash:w:$(HEX_NAME)