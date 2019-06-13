#include "serial.h"


#define INTR_ENABLE  asm volatile ("sei")
#define INTR_DISABLE asm volatile ("cli")

int putc(unsigned char c) {
	if (c == '\n') {
		serial_send_byte('\r');
	}
	return serial_send_byte(c);
}

unsigned char getc() {
	return serial_recv_byte();
}

void t0a() {
	putc('A');
	putc('B');
	return;
}

void t0b() {
	putc('B');
	return;
}

void t0c() {
	putc('c');
	return;
}

int main(void) {

//	int i = 0;

	INTR_DISABLE;

	vector_init();
	serial_init();
	timer_init();

//	putc('D');
//	char c = getc();
//	putc(++c);

	INTR_ENABLE;

	while (1) {
//		++i;

//		putc('\n');
	}

	return 0;
}
