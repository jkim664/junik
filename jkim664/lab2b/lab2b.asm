;number to print in decimal is in R3.
;it will be positive.
.ORIG x3000

	AND R0, R0, #0
	AND R1, R1, #0 
	AND R2, R2, #0
	AND R4, R4, #0 ; quotient counter
	AND R5, R5, #0
	AND R6, R6, #0
	ADD R1, R1, #-10 ; value of -10
	ADD R2, R2, #10 ; value of 10
	LD R6, ASCII_0	; value of the ascii value 0
	JSR DIV ; jump to division subroutine


ASCII_0 .FILL x30
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0-quotient, R1-remainder
DIV	
	ADD R3, R3, R1 ; subtract 10 
	BRn REMAINDER ; if negative, go to REMAINDER
	ADD R4, R4, #1 ; increment quotient counter
	BRnzp DIV


REMAINDER
	ADD R0, R3, R2 ; add 10 to restore value of R3 and load into R0
	JSR PUSH 
	AND R0, R0, #0 ; clear R0
	AND R3, R3, #0 ; clear R3
	ADD R3, R4, #0 ; Transfer quotient from R4 to R3
	BRz POPPIN ; if quotient is 0, start popping values
	AND R4, R4, #0 ; clear R4
	BRnzp DIV

POPPIN
	JSR POP 
	ADD R5, R5, #0
	BRp STOP ; check if underflow
	ADD R0, R0, R6 ; add popped value with ascii value of 0
	OUT 
	BRnzp POPPIN



STOP	HALT	


;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACk_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		;stack is full
	STR R0, R4, #0		;no overflow, store value in the stack
	ADD R4, R4, #-1		;move top of the stack
	ST R4, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


;OUT: R0, OUT R5 (0-success, 1-fail/underflow)
;R3 STACK_START R4 STACK_TOP
;
POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3		;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET


POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;

.END
