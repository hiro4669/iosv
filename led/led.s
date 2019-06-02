	.section	.text
	.global		lightOn
	.type		lightOn,@function

lightOn:
	ldi	R16,	0b00100000 ; PB5 is Output, Others are Input
	out   	0x04,	R16	   ; 0x04 = DDRB
	ldi	R16,	0b00100000 ; PB5 is High (1 = High, 0 = Low)
	out	0x05,	R16	   ; 0x05 = PORTB
	;;   	rjmp	lightOn
 	ret

