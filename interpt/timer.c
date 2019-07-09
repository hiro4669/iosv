#include "timer.h"

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
