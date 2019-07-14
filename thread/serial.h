#ifndef _SERIAL_H_INCLUDED_
#define _SERIAL_H_INCLUDED_

int serial_init();                         /* デバイス初期化 */
int serial_is_send_enable();               /* 送信可能か？ */
int serial_send_byte(unsigned char b);     /* １文字送信 */
int serial_is_recv_enable();               /* 受信可能か？ */
unsigned char serial_recv_byte();          /* １文字受信 */

#endif
