//#include "serial.h"

/*
int putc(unsigned char c) {
	if (c == '\n') {
		serial_send_byte('\r');
	}
	return serial_send_byte(c);
}

unsigned char getc() {
	return serial_recv_byte();
}
*/

void setout();
void turnon();
void turnoff();

int flg = 1;

int wait(int seed) {
    int i;
    int rand = 1;
    for (i = seed; i < seed+32000; ++i) {
	rand++;
    }
    return rand;
}



int main(void) {

    //	serial_init();
	setout();

	/*
	putc('D');
	char c = getc();
	turnon();
	putc(++c);
	c = getc();
	getc();
	c = getc();
	putc(++c);
	turnoff();
	*/
	turnoff();
	int flg = 1;
	int v = 1;
	while(1) {
	    if (flg == 0) {
		turnon();
		flg = 1;
	    } else if (flg == 1) {
		turnoff();
		flg = 0;
	    }
	    wait(v);
	    wait(v);
	    wait(v);
	    v++;
	}

	return 0;
}
