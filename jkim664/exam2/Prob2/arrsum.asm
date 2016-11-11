.ORIG x3000

;;R5 - frame pointer
;;R6 - stack pointer
;;MAIN - DO NOT CHANGE ANY CODE HERE
	LD R6, STACK
	LD R5, STACK
	ADD R6, R6, 1	; runtime stack is empty
	ADD R6, R6, -1	; space for x

	AND R0, R0, 0	; counter for # of elements in array
	ADD R0, R0, 4	
	AND R1, R1, 0	; values of array
	ADD R1, R1, 4
INITARR
	ADD R6, R6, -1	; space for arr[i]
	STR R1, R6, 0	; initialize array cell with value
	ADD R1, R1, -1	; decrement value(4,3,2,1)
	ADD R0, R0, -1	; decrement R0 by 1	
	BRp INITARR	; check whether its done 4 times 

;IMPLEMENT ME: stack build up - prepare to call ARRAY_SUM
	ADD R6, R6, #-1
	LDR R0, R5, #-4
	STR R0, R6, #0
	ADD R6, R6, #-1
	LDR R0, R5, #-3
	STR R0, R6, #0
	ADD R6, R6, #-1
	LDR R0, R5, #-2
	STR R0, R6, #0
	ADD R6, R6, #-1
	LDR R0, R5, #-1
	STR R0, R6, #0
	

	

;IMPLEMENT ME: call ARRAY_SUM
	JSR ARRAY_SUM	


;IMPLEMENT ME: stack tear down after returning from ARRAY_SUM 
	LDR R0, R6, #0
	STR R0, R5, #0
	ADD R6, R6, #4


;IMPLEMENT ME: return 0
	HALT
	

;----------END OF MAIN----------

;ARRAY_SUM subroutine starts here
ARRAY_SUM
;IMPLEMENT ME: stack build up at ARRAY_SUM
	ADD R6, R6, #-1
	ADD R6, R6, #-1
	STR R7, R6, #0
	ADD R6, R6, #-1
	STR R5, R6, #0
	ADD R5, R6, #-1
	
	ADD R6, R6, #-1
	ADD R6, R6, #-1
	AND R0, R0, #0
	STR R0, R5, #0
	STR R0, R5, #-1
	
		
;IMPLEMENT ME: Calculation
	AND R3, R3, #0
	ADD R3, R3, #7
	ADD R3, R3, R5	
	
	LDR R0, R3, #0 
	LDR R1, R5, #-1
	ADD R2, R0, R1
	STR R2, R5, #-1
	LDR R0, R5, #0
	ADD R0, R0, #1
	STR R0, R5, #0	

	AND R3, R3, #0
	ADD R3, R3, #6
	ADD R3, R3, R5	
	
	LDR R0, R3, #0 
	LDR R1, R5, #-1
	ADD R2, R0, R1
	STR R2, R5, #-1
	LDR R0, R5, #0
	ADD R0, R0, #1
	STR R0, R5, #0		
	
	AND R3, R3, #0
	ADD R3, R3, #5
	ADD R3, R3, R5	
	
	LDR R0, R3, #0 
	LDR R1, R5, #-1
	ADD R2, R0, R1
	STR R2, R5, #-1
	LDR R0, R5, #0
	ADD R0, R0, #1
	STR R0, R5, #0	

	AND R3, R3, #0
	ADD R3, R3, #4
	ADD R3, R3, R5	
	
	LDR R0, R3, #0 
	LDR R1, R5, #-1
	ADD R2, R0, R1
	STR R2, R5, #-1
	LDR R0, R5, #0
	ADD R0, R0, #1
	STR R0, R5, #0	
	
	LDR R0, R5, #-1
	STR R0, R5, #3

;IMPLEMENT ME: stack tear down - prepare to go back to main

	ADD R6, R6, #2
	LDR R5, R6, #0
	ADD R6, R6, #1
	LDR R7, R6, #0
	ADD R6, R6, #1	

	RET


STACK .FILL x6000

.END
