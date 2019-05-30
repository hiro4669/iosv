	.section .text
	.global start
	.type   start, @function

start:
	mov r16, r16
	ldi r20, 0x2
	ldi r17, 0x1
	lds r18, 0x40
	add r18, r17
	sts 0x40, r18
	lds r19, 0x40
	mov r16, r16

;start:
;	ldi r16, 0b00100000
;	out 0x04, r16
;	ldi r16, 0b00000000
;	out 0x05, r16
;	ldi r28, lo8(_bootstack)
;	ldi r29, hi8(_bootstack)
;	out 0x3d, r28
;	out 0x3e, r29
;	jmp call_main
;
;call_main:
;	rcall main
;
;	.globl turnon
;	.type  turnon, @function
;turnon:
;	push r16
;	ldi r16, 0b00100000
;	out 0x5, r16
;	pop r16
;	ret
;
;	.globl turnoff
;	.type  turnoff, @function
;turnoff:
;	push r16
;	ldi r16, 0b00000000
;	out 0x5, r16
;	pop r16
;	ret



