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
    char head[] = {'0', 'x', 0};
    puts(head);
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

void *memcpy(void* dst, const void *src, long len) {
    char *d = dst;
    const char *s = src;
    for (; len > 0; --len)
        *(d++) = *(s++);
    return dst;
}

void *memset(void* b, int c, long len) {
    char *p;
    for (p = b; len > 0; --len) {
        *(p++) = c;
    }
    return b;
}

void cpdata() {
    extern long _rodata_start, _edata, _etext;
    extern long _bss_start, _ebss;
    memcpy(&_rodata_start, &_etext, (unsigned long)&_edata - (unsigned long)&_rodata_start);
    memset(&_bss_start, 0, (unsigned long)&_ebss - (unsigned long)&_bss_start);
}



volatile int value = 10;

int main (void)
{
    int i;
    extern char _bootstack;
    static char *ts = &_bootstack;

//    cpdata();

    serial_init();
    char str1[] = {'a','b','\n', '\0'};

    char *s = "hello world\n";
    puts(s);
    puts(str1);
    putxval(value);
    putxval((unsigned long)ts);
    for (i = 0; i < 5; ++i) {
	    puts(s);
    }
    return 0;
}
