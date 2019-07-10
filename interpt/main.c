#include "timer.h"
#include "serial.h"
#include "libc.h"

#define INTR_ENABLE  asm volatile ("sei")
#define INTR_DISABLE asm volatile ("cli")

void vector_init();

void t0a() {
    puts("ABC\n");
    putxval(16);
	return;
}

int main(void) {

	INTR_DISABLE;

	vector_init();
	serial_init();
	timer_init();

	INTR_ENABLE;

	while (1) {
//		++i;
//		putc('\n');
	}

	return 0;
}
