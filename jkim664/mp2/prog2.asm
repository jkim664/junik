;Assuming user will only enter ' ' 0-9 *+/-
;Intro paragraph : this code first checks if the input is a newline or a space. If not, 
;it jumps to the evaluation subroutine, where it checks if the input is an operand or
;an operator. Then, accordingly, if it's a number, then it'll be pushed. If it's an 
;operator, the stored numbers will be popped. If there is no number to pop, the system
;redirects to the invalid subroutine. Also, other invalid expressions such as dividing by
;zero will redirect to the invalid subroutine. 
;
;
.ORIG x3000
	
;your code goes here

START	AND R1, R1, #0
	AND R2, R2, #0
	AND R3, R3, #0
	AND R4, R4, #0
	AND R5, R5, #0
	AND R0, R0, #0 ; clearing all registers 
	GETC
	OUT
	ADD R0, R0, #-10 ; check if it's new line 
	BRz NEWLINE 
	ADD R0, R0, #-3 ; check again if it's new line
	BRz NEWLINE 
	ADD R0, R0, #-10
	ADD R0, R0, #-9 ; check if it's space
	BRz START 
	JSR EVALUATE 
	



NEWLINE
	JSR POP
	AND R3, R3, #0
	ADD R3, R3, R0 ; store whatever is in stack into R3
	JSR POP
	ADD R5, R5, #0 ; check if underflow
	BRp PRINT_HEX ; if underflow, print
	BRz INVALID ; if more than 1 value, invalid






INVALID
	LEA R1, STRING_START ; load address of string 
	AND R2, R2, #0 ; clear R2
	ADD R2, R2, #15 
	ADD R2, R2, #4 ; counter for number of letters
INVAL	LDR R0, R1, #0 ; load R0 with data of R1
	OUT
	ADD R1, R1, #1 ; incrememnt memory address
	ADD R2, R2, #-1 ; decrement letter counter 
	BRp INVAL
	BRz END



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R3- value to print in hexadecimal
PRINT_HEX

	AND R1, R1, #0	;clearing registers 
	AND R2, R2, #0
	AND R4, R4, #0	;where the bits will be stored from R3
	AND R0, R0, #0	
	ADD R1, R1, #4  ;character counter
	AND R5, R5, #0
	ADD R5, R5, R3 ; put the calculated value into R5 
	

Q	BRz END 
	ADD R2, R2, #4	;bit counter
START1	AND R3, R3, R3	;set cc	
	BRn ADD1
	BRzp ADD0

ADD1	ADD R4, R4, R4 	;left shift
	ADD R4, R4, #1	;add 1
	BRnzp SHIFT	

ADD0 	ADD R4, R4, R4	;left shift	
	BRnzp SHIFT

SHIFT 	ADD R3, R3, R3 ;shift R3 to the left
	ADD R2, R2, #-1 ;subtract from bit counter
	BRp START1 
	BRnz CHECK 

CHECK	ADD R4, R4, #-10 ;check if it's digit or letter
	BRn DIGIT
	BRzp LETTER

DIGIT	ADD R4, R4, #10 ;add to find ascii 
     	ADD R4, R4, #10 	
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #8
	BRnzp PRINT

LETTER	ADD R4, R4, #10 ;add to find ascii
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #5
	BRnzp PRINT

PRINT 	ADD R0, R4, #0 ;load to R0 to TRAP out
	OUT
	AND R4, R4, #0 ;Clear bit holder 
	ADD R1, R1, #-1 ;subtract from character counter
	BRnzp Q
	
 ; stop the computer
 END	HALT

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;R0 - character input from keyboard
;R6 - current numerical output
;
;
EVALUATE
;your code goes here

	ADD R0, R0, #-10 ; check if it's multiplication
	BRz MUL
	ADD R0, R0, #-1	; check if it's addition
	BRz PLUS
	ADD R0, R0, #-2 ; check if it's subtraction
	BRz MIN
	ADD R0, R0, #-2 ; check if it's division
	BRz DIV
	ADD R0, R0, #-10 ; check if it's a number
	BRnz NUMBER
	BRp EXP 


NUMBER
	ADD R0, R0, #9 ; restore to decimal number value
	JSR PUSH
	BRnzp START

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
PLUS	
;your code goes here
	JSR POP
	ADD R1, R0, #0 ; store the first value into R1
	ADD R5, R5, #0 ; set cc
	BRp INVALID
	AND R0, R0, #0 ; clear R0
	JSR POP
	ADD R2, R0, #0 ; store the second value into R2
	ADD R5, R5, #0 ; set cc
	BRp INVALID
	AND R0, R0, #0 ; clear R0
	ADD R0, R1, R2 ; add the two numbers
	JSR PUSH 
	BRnzp START
	
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MIN	
;your code goes here
	JSR POP
	ADD R1, R0, #0 ; store the first value into R1
	ADD R5, R5, #0 ; set cc
	BRp INVALID
	AND R0, R0, #0 ; clear R0
	JSR POP
	ADD R2, R0, #0; store the second value into R2
	ADD R5, R5, #0; set cc
	BRp INVALID
	AND R0, R0, #0 ; clear R0
	NOT R1, R1
	ADD R1, R1, #1 ; 2's complement of second value
	ADD R0, R2, R1 ; subtract the two numbers 
	JSR PUSH 
	BRnzp START


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
MUL	
;your code goes here
	JSR POP
	ADD R0, R0, #0 ; set cc
	BRz ZEROM2 ; if multiplicand is zero, then the number is zero
	ADD R5, R5, #0 ; set cc
	BRp INVALID 	
	ADD R1, R1, R0 ; store the first value into R1
	AND R0, R0, #0
	JSR POP
	ADD R0, R0, #0 ; set cc
	BRz ZEROM1 
	ADD R5, R5, #0 ; set cc
	BRp INVALID
	ADD R2, R2, R0 ; store the second value into R2
	AND R3, R3, #0
MLOOP	ADD R3, R3, R1 ; start multiplication
	ADD R2, R2, #-1 ; decrement multiplication counter 
	BRp MLOOP
	AND R0, R0, #0 
	ADD R0, R0, R3 ; put R3 into R0 for push
ZEROM1	JSR PUSH
	BRnzp START

ZEROM2	JSR POP
	AND R0, R0, #0
	JSR PUSH
	BRnzp START	
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
DIV	
;your code goes here
	JSR POP
	ADD R0, R0, #0 ; setcc
	BRz INVALID ; invalid if denominator is 0
	ADD R5, R5, #0 ; set cc
	BRp INVALID
	ADD R1, R1, R0 ; store the first value into R1
	AND R0, R0, #0
	JSR POP
	ADD R5, R5, #0 ; set cc
	BRp INVALID
	ADD R2, R2, R0 ; store the second value into R2
	NOT R1, R1
	ADD R1, R1, #1 ; 2's complement of R1
	AND R3, R3, #0
DLOOP	ADD R2, R1, R2 ; start division
	BRn DBREAK
	ADD R3, R3, #1 ; increment quotient counter 
	BRnzp DLOOP ; if negative, quotient found
DBREAK	AND R0, R0, #0
	ADD R0, R0, R3
	JSR PUSH
	BRnzp START 

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;input R3, R4
;out R0
EXP
;your code goes here
	JSR POP
	ADD R0, R0, #0
	BRz ZEROE2 ; if exponent is 0, then number is 1 
	ADD R5, R5, #0 ; set cc
	BRp INVALID
	ADD R1, R1, R0 ; store first value into R1
	AND R0, R0, #0
	JSR POP
	ADD R0, R0, #0 ; set cc
	BRz ZEROE1 ; if base is 0, the number is 0
	ADD R5, R5, #0 ; set cc
	BRp INVALID
	ADD R2, R2, R0 ; store second value into R2
	AND R3, R3, #0 ; clear 
	AND R4, R4, #0 ; clear
	ADD R3, R2, #0 ; value of base into R3
ELOOP2	ADD R1, R1, #-1 ; subtract from the exponent
	BRz EBREAK ; if 0, then done taking power
	ADD R4, R3, #0 ; store multiplied value into R4
	ADD R5, R2, #0 ; store original value into R5 multiplcation counter
	AND R3, R3, #0 ; clear R3
ELOOP1	ADD R3, R3, R4 ; multiplication	
	ADD R5, R5, #-1; decrement multiplcation counter 
	BRz ELOOP2
	BRp ELOOP1

EBREAK	AND R0, R0, #0
	ADD R0, R0, R3
ZEROE1	JSR PUSH
	BRnzp START

ZEROE2	ADD R0, R0, #1
	JSR PUSH
	BRnzp START


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

STRING_START	.FILL xA
		.FILL x49
		.FILL x6E
		.FILL x76
		.FILL x61
		.FILL x6C
		.FILL x69
		.FILL x64
		.FILL x20
		.FILL x45
		.FILL x78
		.FILL x70
		.FILL x72
		.FILL x65
		.FILL x73
		.FILL x73
		.FILL x69
		.FILL x6F
		.FILL x6E






.END
