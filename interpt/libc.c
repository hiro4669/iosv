#include "serial.h"

int putc(unsigned char c) {
	if (c == '\n') {
		serial_send_byte('\r');
	}
	return serial_send_byte(c);
}

unsigned char getc() {
	return serial_recv_byte();
}

int puts(char *str) {
    while (*str) {
        putc(*(str++));
    }
    return 0;
}


int putxval(unsigned long value) {
    char buf[9];
    char *p;
    p = buf + sizeof(buf) - 1;
    *(p--) = '\0';
    while (value) {
        *(p--) = "0123456789abcdef"[value & 0xf];
        value >>= 4;
    }
    puts(p + 1);
    putc('\n');
    return 0;
}
