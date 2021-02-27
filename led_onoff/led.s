	.section .text
	.globl setout
	.type  setout, @function	

setout:
	push r16
	ldi r16, 0b00100000
	out 0x4, r16
	pop r16
	ret
	

	.globl turnon
	.type  turnon, @function
turnon:
	push r16
	ldi r16, 0b00100000
	out 0x5, r16
	pop r16
	ret

	.globl turnoff
	.type  turnoff, @function
turnoff:
	push r16
	ldi r16, 0b00000000
	out 0x5, r16
	pop r16
	ret



