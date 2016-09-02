;modified POP to store value in R6.
;read comments
;
.ORIG x3000
START	AND R0, R0, #0
	GETC
	OUT
	ADD R0, R0, #-10
	BRz NLINE
	ADD R0, R0, #-3
	BRz NLINE
	ADD R0, R0, #-7
	ADD R0, R0, #-12
	BRz START
	JSR IS_BALANCED
	


SPACE	.FILL x0020
NEW_LINE	.FILL x000A
CHAR_RETURN	.FILL x000D
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;if ( push onto stack if ) pop from stack and check if popped value is (
;input - R0 holds the input
;output - R5 set to -1 if unbalanced. else not modified.
IS_BALANCED
	ADD R0, R0, #-8
	BRz LEFT
	BRp RIGHT
	
LEFT	ADD R0, R0, #10
	ADD R0, R0, #15
	ADD R0, R0, #15
	JSR PUSH 
	BRnzp START

RIGHT	ADD R0, R0, #10
	ADD R0, R0, #15
	ADD R0, R0, #15
	JSR POP
	LD R1, NEG_OPEN
	ADD R1, R1, R0	
	BRz START
	ADD R5, R5, #-2
	BRp EXIT 	
	

NLINE	ADD R5, R5, #0
	BRp DONE
	BRnz EXIT
	
	

EXIT	JSR POP
	LD R1, NEG_OPEN
	ADD R1, R1, R0	
	BRnp DONE
	ADD R5, R5, #-1
	

DONE	HALT	




NEG_OPEN .FILL xFFD8
;IN:R0, OUT:R5 (0-success, 1-fail/overflow)
;R3: STACK_END R4: STACK_TOP
;
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;
	LD R4, STACK_TOP	;
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
        ST R3, POP_SaveR3       ;save R3
        ST R4, POP_SaveR4       ;save R3
        AND R5, R5, #0          ;clear R5
        LD R3, STACK_START      ;
        LD R4, STACK_TOP        ;
        NOT R3, R3              ;
        ADD R3, R3, #1          ;
        ADD R3, R3, R4          ;
        BRz UNDERFLOW	        ;
        ADD R4, R4, #1          ;
        LDR R0, R4, #0          ;
        ST R4, STACK_TOP        ;
        BRnzp DONE_POP          ;
UNDERFLOW
        ADD R5, R5, #1          ;
	BRnzp DONE_POP
				;
DONE_POP
        LD R3, POP_SaveR3       ;
        LD R4, POP_SaveR4       ;
        RET


POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;

.END


