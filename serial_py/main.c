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

void setout();
void turnon();
void turnoff();

int main(void) {

	serial_init();
	setout();


	putc('D');
	char c = getc();

	turnon();	
	putc(++c);
	putc('E');
	c = getc();

	turnoff();	
	putc(++c);


	while(1) {
	}

	return 0;
}
