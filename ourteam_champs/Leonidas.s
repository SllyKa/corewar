.name		"Leonidas, warrior-king of Sparta"
.comment	"This is SPARTAAAA!"

	ld		%16777216, r15
	ld		%167770880, r14
	ld		%00000036, r2
	ld		%00000008, r3
	ld		%-327680, r4
	ld		%524288, r5
loop:

	add		r4, r5, r4
	add		r2, r3, r2
	ld		%0, r16
	sti		r15, r2, %0
	sti		r1, r2, %-5
	sti		r14, r2, %-7
	st		r1, 6
	live	%99
	fork	%6
	zjmp	%:loop
endloop:
	st		r4, 6
	zjmp	%99
