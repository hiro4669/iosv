#include "timer.h"
#include "serial.h"
#include "libc.h"

#define INTR_ENABLE  asm volatile ("sei")
#define INTR_DISABLE asm volatile ("cli")
#define NULL ((void *)0)

void vector_init();

void dispatch(unsigned int *sp);

typedef void (*thread_func)();

typedef struct {
    char *stack;
    unsigned int sp;
} context_t;


static int idx = 0;
//static context_t *current = NULL;
static context_t contexts[1];

void* memset(void *b, int c, long len) {
    char *p;
    for (p = b; len > 0; --len) {
        *(p++) = c;
    }
    return b;
}


void t0a(unsigned int sp) {
    extern char _intrstack;
    char *ts = &_intrstack;
//    puts("ABCD\n");
//    putxval(16);
/*
    if (current == NULL) {
        putxval((unsigned long)ts);
    } else {
        putxval((unsigned long)sp);
    }
*/
	return;
}

void handle(unsigned int sp) {
//    putxval((unsigned long)sp);
    contexts[idx].sp = sp;
    if (idx == 0) {
        idx = 1;
//        puts("0\n");
    } else {
        idx = 0;
//        puts("1\n");
    }
    dispatch(&contexts[idx].sp);
}

void test_t() {
    while (1) {
        puts("ABCDEFG\n");
    }
}

void test_t2() {
    while (1) {
        puts("1234567\n");
    }
}

void thread_end() {
//    current = NULL;
    puts("end");
    while(1) {
    }
}

void thread_create(thread_func f, int idx) {
    int i;
    int stacksize = 128;
    unsigned char *sp;
    extern char _userstack;
    static char *thread_stack = &_userstack;
    context_t *current = NULL;
    current = &contexts[idx];

    memset(current, 0, sizeof(*current));

//    putxval((unsigned long)thread_stack);

    current->stack = thread_stack;
    memset(thread_stack - stacksize, 0, stacksize);
    thread_stack -= stacksize;

    sp = (unsigned char*) current->stack;
    *(sp--) = (unsigned char) (((unsigned int)thread_end >> 0) & 0xff);
    *(sp--) = (unsigned char) (((unsigned int)thread_end >> 8) & 0xff);

    *(sp--) = (unsigned char) (((unsigned int)f >> 0) & 0xff);
    *(sp--) = (unsigned char) (((unsigned int)f >> 8) & 0xff);

    *(sp--) = 0; // SREG

    for (i = 31; i >= 0; --i) {
        *(sp--) = 0;
    }
//    putxval((unsigned long)sp);
    current->sp = (unsigned int)sp;
//    putxval(current->sp);
//    putxval(&current->sp);

}



int main(void) {
	INTR_DISABLE;

	vector_init();
	serial_init();

    thread_create(test_t, 0);
    thread_create(test_t2, 1);
	timer_init();

	INTR_ENABLE;
//    if (current != NULL) {
//        puts("current go\n");
//        dispatch(&current->sp);
//        dispatch(&contexts[idx].sp);
//    }
    dispatch(&contexts[idx].sp);

    // Never reach here
	while (1) {
        puts("CCCCC");
	}

	return 0;
}
