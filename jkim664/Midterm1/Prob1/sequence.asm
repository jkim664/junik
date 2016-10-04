.ORIG x3000

lea r0, stringInput ;input character
puts
;;START YOUR CODE HERE
	AND R1, R1, #0
	AND R2, R2, #0
	AND R0, R0, #0
	AND R3, R3, #0
	AND R4, R4, #0
	AND R6, R6, #0
	
LOOP	GETC
	OUT
	ADD R0, R0, #-15
	ADD R0, R0, #-15
	ADD R0, R0, #-12
	BRz END
	ADD R2, R3, #0
	AND R1, R1, #0
	ADD R1, R0, #0
	AND R3, R3, #0
	ADD R3, R1, #0
	NOT R1, R1
	ADD R1, R1, #1
	ADD R2, R2, R1
	BRn ADD1
	AND R6, R6, #0
	ADD R6, R6, #1
	BRnzp LOOP


ADD1	ADD R6, R6, #1
	ADD R4, R5, #0
	AND R0, R0, #0
	ADD R0, R6, #0
	NOT R0, R0
	ADD R0, R0, #1
	ADD R5, R5, R0
	BRn NEW
	BRzp NONE

NONE	AND R5, R5, #0
	ADD R5, R4, #0
	AND R4, R4, #0
	BRnzp LOOP

NEW	AND R5, R5, #0
	ADD R5, R6, #0
	BRnzp LOOP

END	AND R6, R6, #0
	ADD R6, R5, #0	
	HALT


stringInput .stringz "Please input number: "
maxLength .fill 0
length .fill 0
previous .fill 0
current .fill 0
.END
