	.section .text
	.global start
	.type   start, @function
	.global reset
	.type   reset, @function

reset:
	jmp start
	jmp reset
	jmp reset
	jmp reset

;start:
;	mov r0, r0
;	ldi r28, 0x2

start:
	mov r0, r0
	ldi r28, lo8(_bootstack)
	ldi r29, hi8(_bootstack)
	out 0x3d, r28
	out 0x3e, r29
	jmp call_main

call_main:
	rcall main

