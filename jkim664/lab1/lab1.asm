 ; Lab 1 
 ; assignment: develop a code to print a value stored in a register 
 ;             as a hexadecimal number to the monitor
 ; algorithm: turnin each group of four bits into a digit
 ;            calculate the corresponding ASCII character;
 ;            print the character to the monitor

 .ORIG x3000
	AND R1, R1, #0	
	AND R2, R2, #0
	AND R4, R4, #0	
	AND R0, R0, #0	
	ADD R1, R1, #4  ;character counter
	

Q	BRz END 
	ADD R2, R2, #4
START	AND R3, R3, R3	;set cc	
	BRn ADD1
	BRzp ADD0

ADD1	ADD R4, R4, R4 
	ADD R4, R4, #1	;add 1
	BRnzp SHIFT	

ADD0 	ADD R4, R4, R4	;left shift	
	BRnzp SHIFT

SHIFT 	ADD R3, R3, R3 ;shift R3 to the left
	ADD R2, R2, #-1 ;subtract from bit counter
	BRp START 
	BRnz CHECK 

CHECK	ADD R4, R4, #-10
	BRn DIGIT
	BRzp LETTER

DIGIT	ADD R4, R4, #10
     	ADD R4, R4, #10 	
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #8
	BRnzp PRINT

LETTER	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #10
	ADD R4, R4, #5
	BRnzp PRINT

PRINT 	ADD R0, R4, #0 
	OUT
	AND R4, R4, #0	
	ADD R1, R1, #-1 
	BRnzp Q
	




 ; stop the computer
 END	HALT

 ; program data section starts here


 .END

