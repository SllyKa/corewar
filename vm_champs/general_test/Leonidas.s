.name		"Leonidas, warrior-king of Sparta"
.comment	"This is SPARTAAAA!"

live:
	st		r1, 6
	live	%99
	ld		%0, r16
	fork	%7
	zjmp	%:live
	aff		r1
	ld		%-4, r3
	st		r3, 20
	ld		%-18, r3
	st		r3, 16
