PREFIX = avr-elf
BASEDIR = /usr/local/core/$(PREFIX)
BINDIR = $(BASEDIR)/bin

AS = $(BINDIR)/avr-as
NM = $(BINDIR)/avr-nm
CC = $(BINDIR)/avr-gcc
LD = $(BINDIR)/avr-ld
READELF = $(BINDIR)/avr-readelf
OBJDMP = $(BINDIR)/avr-objdump
OBJCPY = $(BINDIR)/avr-objcopy
GDB = $(BINDIR)/avr-gdb
PORT=/dev/cu.usbmodem1411 # PORT


OBJS = startup.o 

TARGET = startup
SRC = $(TARGET).s

CFLAGS = -Wall -nostdinc -nostdlib -fno-builtin
CFLAGS += -mmcu=avr5
CFLAGS += -g
CFLAGS += -Os

LFLAGS = -static -T ld.scr -L.

.SUFFIXES: .c .o
.SUFFIXES: .s .o

all: $(SRC)
	$(AS) -mmcu=avr5 $(SRC)


$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET) $(CFLAGS) $(LFLAGS)
	cp $(TARGET) $(TARGET).elf

.c.o :	$<
	$(CC) -c $(CFLAGS) $<

.s.o :	$<
	$(CC) -c $(CFLAGS) $<

$(TARGET).hex :	$(TARGET)
		$(OBJCPY) -O ihex $(TARGET) $(TARGET).hex

image: $(TARGET).hex

#upload: image
#	/usr/core/avrdude-6.3/bin/avrdude -V -F -p m328p -C ./avrdude.conf -c arduino -b 115200 -Uflash:w:$(TARGET).hex -P$(PORT)


dump: a.out
	$(OBJDMP) -d $^

sym: a.out
	$(NM) $^

run: a.out
	$(GDB) $^

clean:
	rm -rf $(OBJS) $(TARGET) $(TARGET).elf $(TARGET).hex a.out *~
