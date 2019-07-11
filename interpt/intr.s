	.global intr_time
	.type   intr_time, @function
;intr_time:
;	cli
;	rcall t0a
;	reti


;intr_time:
;    cli
;    push r31
;    push r30
;    push r29
;    push r28
;    push r27
;    push r26
;    push r25
;    push r24
;    push r23
;    push r22
;    push r21
;    push r20
;    push r19
;    push r18
;    push r17
;    push r16
;    push r15
;    push r14
;    push r13
;    push r12
;    push r11
;    push r10
;    push r9
;    push r8
;    push r7
;    push r6
;    push r5
;    push r4
;    push r3
;    push r2
;    push r1
;    push r0
;    in r31, 0x3f ; save SREG to r31
;    push r31     ; push SREG
;    rcall t0a
;    pop r31        ; pop SREG to r31
;    out 0x3f, r31  ; set SREG
;    pop r0
;    pop r1
;    pop r2
;    pop r3
;    pop r4
;    pop r5
;    pop r6
;    pop r7
;    pop r8
;    pop r9
;    pop r10
;    pop r11
;    pop r12
;    pop r13
;    pop r14
;    pop r15
;    pop r16
;    pop r17
;    pop r18
;    pop r19
;    pop r20
;    pop r21
;    pop r22
;    pop r23
;    pop r24
;    pop r25
;    pop r26
;    pop r27
;    pop r28
;    pop r29
;    pop r30
;    pop r31
;    reti

intr_time:
        cli
        push r31
        push r30
        push r29
        push r28
        push r27
        push r26
        push r25
        push r24
        push r23
        push r22
        push r21
        push r20
        push r19
        push r18
        push r17
        push r16
        push r15
        push r14
        push r13
        push r12
        push r11
        push r10
        push r9
        push r8
        push r7
        push r6
        push r5
        push r4
        push r3
        push r2
        push r1
        push r0
        in   r31, 0x3f ; SREG
        push r31
        in   r22, 0x3d ; save current sp low  to r22
        in   r23, 0x3e ; save current sp high to r23
        ldi  r28, lo8(_userstack) ; save userstack lo byte to r28
        ldi  r29, hi8(_userstack) ; save userstack hi byte to r29
        out  0x3d, r28 ; save userstack low   ; change sp to userstack
        out  0x3e, r29 ; save userstack high
        push r22
        push r23
        eor  r1, r1

        rcall t0a

        pop r29        ; pop old sp hi  from userstack
        pop r28        ; pop old sp low from userstack
        out 0x3d, r28  ; set sp low
        out 0x3e, r29  ; set sp high   -> change sp to original
        pop r31        ; restore SREG to r31
        out 0x3f, r31  ; set SREG
        pop r0
        pop r1
        pop r2
        pop r3
        pop r4
        pop r5
        pop r6
        pop r7
        pop r8
        pop r9
        pop r10
        pop r11
        pop r12
        pop r13
        pop r14
        pop r15
        pop r16
        pop r17
        pop r18
        pop r19
        pop r20
        pop r21
        pop r22
        pop r23
        pop r24
        pop r25
        pop r26
        pop r27
        pop r28
        pop r29
        pop r30
        pop r31
        reti
