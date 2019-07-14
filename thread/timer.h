#ifndef _TIMER_H_
#define _TIMER_H_

#define IO_OFFSET 0x20

#define MEM8(addr) (*(volatile unsigned char *)(addr))
#define IO8(addr)  MEM8((addr) + IO_OFFSET)

#define TCCR0A  IO8(0x24)
#define TCCR0B  IO8(0x25)
#define TIMSK0  MEM8(0x6E)
#define OCR0A   IO8(0X27)
#define OCR0B   IO8(0X28)

void timer_init();

#endif
