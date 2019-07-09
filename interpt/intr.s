	.global intr_time
	.type   intr_time, @function
intr_time:
	cli
	rcall t0a
	reti
