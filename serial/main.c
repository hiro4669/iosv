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

int main(void) {

	serial_init();

	putc('D');
	char c = getc();
	putc(++c);

	while (1) {
	}

	return 0;
}
