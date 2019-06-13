#include "serial.h"

#define IO_OFFSET 0x20

#define MEM8(addr) (*(volatile unsigned char *)(addr))
#define IO8(addr)  MEM8((addr) + IO_OFFSET)

#define USART_UCSR0A MEM8(0xc0)

#define USART_UCSR0A_UDRE0 (1<<5) /* 送信バッファが空でセット */
#define USART_UCSR0A_TXC0  (1<<6) /* 送信完了でセット */
#define USART_UCSR0A_RXC0  (1<<7) /* 受信バッファにデータ有りでセット */

#define USART_UCSR0B MEM8(0xc1)
#define USART_UCSR0B_UCSZ02 (1<<2)
#define USART_UCSR0B_TXEN0  (1<<3)
#define USART_UCSR0B_RXEN0  (1<<4)
#define USART_UCSR0B_UDRIE0 (1<<5)
#define USART_UCSR0B_TXCIE0 (1<<6)
#define USART_UCSR0B_RXCIE0 (1<<7)

#define USART_UCSR0C MEM8(0xc2)
#define USART_UCSR0C_UCSZ00      (1<<1)
#define USART_UCSR0C_UCSZ01      (1<<2)
#define USART_UCSR0C_STOPBIT_1   (0<<3)
#define USART_UCSR0C_STOPBIT_2   (1<<3)
#define USART_UCSR0C_PARITY_NONE (0<<4)
#define USART_UCSR0C_PARITY_EVEN (2<<4)
#define USART_UCSR0C_PARITY_ODD  (3<<4)
#define USART_UCSR0C_MODE_ASYNC  (0<<6)
#define USART_UCSR0C_MODE_SYNC   (1<<6)
#define USART_UCSR0C_MODE_SPI    (3<<6)

#define USART_UBRR0L MEM8(0xc4)
#define USART_UBRR0H MEM8(0xc5)

#define USART_UDR0   MEM8(0xc6)

#define MCUCR_IO    IO8(0x35)
#define MCUCR_IVCE  (1<<0)
#define MCUCR_IVSEL (1<<1)

#define TCCR0A  IO8(0x24)
#define TCCR0B  IO8(0x25)
#define TIMSK0  MEM8(0x6E)
#define OCR0A   IO8(0X27)
#define OCR0B   IO8(0X28)


void vector_init() {
  MCUCR_IO = MCUCR_IVCE;
  MCUCR_IO = 0;
}

int serial_init() {
  //MCUCR_IO = MCUCR_IVCE;
  //MCUCR_IO = 0;


  USART_UCSR0B = 0;

#define CPU_CLOCK 16000000L
#define BAUDRATE 9600
  USART_UBRR0L = (CPU_CLOCK / (BAUDRATE * 16L) - 1);
  USART_UBRR0H = (CPU_CLOCK / (BAUDRATE * 16L) - 1) >> 8;

  USART_UCSR0B = USART_UCSR0B_RXEN0 | USART_UCSR0B_TXEN0; /* 送受信可能 */
  USART_UCSR0C = USART_UCSR0C_UCSZ00 | USART_UCSR0C_UCSZ01;

  return 0;
}

int serial_is_send_enable() {
  return (USART_UCSR0A & USART_UCSR0A_UDRE0);
}

int serial_send_byte(unsigned char c)
{
  while (!serial_is_send_enable())
    ;
  USART_UDR0 = c;
  return 0;
}

int serial_is_recv_enable() {
  return (USART_UCSR0A & USART_UCSR0A_RXC0);
}

unsigned char serial_recv_byte() {
  unsigned char c;

  while (!serial_is_recv_enable())
    ;
  c = USART_UDR0;
  return c;
}

void timer_init() {
	//    タイマ0,CTC,割り込み用、比較A一致で割り込み
    TCCR0A = 0b00000010;
    //TCCR0B = 0b00000011; // N=64
    TCCR0B = 0b00000101; // N=1024
    //OCR0A = 78;  // 5msごとに割り込み
    OCR0A = 235;  // 15msごとに割り込み
    TIMSK0 = 0b0000010;    //比較A一致割り込み有効
//    TIMSK0 = 0b0000111;    //比較A一致割り込み有効
}
