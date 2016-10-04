;Write a program to check whether a given number is a weird number.
;Weird numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are weird while 14 is not since it includes another prime factor 7. You do not need to consider 1 for your program.
;input: a number stored in R3 (a number being set during testing)
;output: if the number stored in R3 is weird, R6 should be set to 1; otherwise R6 should not be set to 1 (can be any other number).


ECEGRADE .FILL  x3000

;; START YOUR CODE HERE

	AND R0, R0, #0
	AND R1, R1, #0
	AND R2, R2, #0
	AND R4, R4, #0
	AND R5, R5, #0
	AND R6, R6, #0

STEP2	AND R4, R4, #0
	ADD R4, R4, #2
	JSR DIVIDE
	ADD R1, R1, #0
	BRz STEP2S

STEP3	AND R4, R4, #0
	ADD R4, R4, #3
	JSR DIVIDE
	ADD R1, R1, #0
	BRz STEP3S

STEP4	AND R4, R4, #0
	ADD R4, R4, #5
	JSR DIVIDE
	ADD R1, R1, #0
	BRz STEP4S

	ADD R6, R3, #0
	HALT




STEP2S	AND R3, R3, #0
	ADD R3, R0, #0 
	BRnzp STEP2

STEP3S 	AND R3, R3, #0
	ADD R3, R0, #0
	BRnzp STEP3

STEP4S 	AND R3, R3, #0
	ADD R3, R0, #0
	BRnzp STEP4

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;DIVIDE SUBROUTINE
;input: R3, R4 
;calculate R3/R4
;out: R0-quotient, R1-remainder
DIVIDE
;;IMPLEMENT SUBROUTINE HERE	
	AND R1, R1, #0
	ADD R5, R4, #0	
	NOT R4, R4
	ADD R4, R4, #1
DLOOP	ADD R3, R3, R4
	ADD R0, R0, #1
	ADD R3, R3, #0
	BRp DLOOP
	BRn DIV1
	BRz DIV2
	
DIV1	ADD R0, R0, #-1
	ADD R3, R3, R5
	ADD R1, R3, #0
DIV2	RET


.END 
