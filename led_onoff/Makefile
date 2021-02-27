PREFIX = avr-elf
BASEDIR = /usr/local/core/$(PREFIX)
BINDIR = $(BASEDIR)/bin

AS = $(BINDIR)/avr-as
NM = $(BINDIR)/avr-nm
CC = $(BINDIR)/avr-gcc
LD = $(BINDIR)/avr-ld
AVRDUDE = $(BINDIR)/avrdude
CONF = $(BASEDIR)/etc/avrdude.conf
READELF = $(BINDIR)/avr-readelf
OBJDUMP = $(BINDIR)/avr-objdump
OBJCOPY = $(BINDIR)/avr-objcopy
GDB = $(BINDIR)/avr-gdb
DEV=/dev/cu.usbmodem142101 # PORT


OBJS = startup.o main.o led.o

TARGET = startup
SRC = $(TARGET).s

CFLAGS = -Wall -nostdinc -nostdlib -fno-builtin
CFLAGS += -mmcu=avr5
CFLAGS += -g
#CFLAGS += -Os

LFLAGS = -static -T ld.scr -L.

.SUFFIXES: .c .o
.SUFFIXES: .s .o

all:	$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET).elf $(CFLAGS) $(LFLAGS)
	$(OBJDUMP) -d $(TARGET).elf > $(TARGET).dump
	$(OBJCOPY) -I elf32-avr -O ihex $(TARGET).elf $(TARGET).hex

.c.o :	$<
	$(CC) -c $(CFLAGS) $<

.s.o :	$<
	$(CC) -c $(CFLAGS) $<

$(TARGET).hex :	$(TARGET)
		$(OBJCPY) -O ihex $(TARGET) $(TARGET).hex

image: $(TARGET).hex

write:
	$(AVRDUDE) -C $(CONF) -c arduino -P $(DEV) -p m328p -b 115200 -D -U flash:w:$(TARGET).hex:i

dump: $(TARGET).elf
	$(OBJDUMP) -d $^

sym: $(TARGET).elf
	$(NM) $^

readelf: $(TARGET).elf
	$(READELF) -a $^

run: $(TARGET).elf
	$(GDB) $^

clean:
	rm -rf $(OBJS) $(TARGET) $(TARGET).elf $(TARGET).hex a.out *~
