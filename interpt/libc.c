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
