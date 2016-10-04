#!/bin/bash

#Example grading script

late_points=$1

#Compilation
echo "Compilation Results:" > grade.txt
echo "********************" >> grade.txt
cp prime.asm gradeprime.asm

lc3as prime.asm >> grade.txt
echo "" >> grade.txt

echo "Test Input 8: R6 should be 1 for full points" >> grade.txt
q1=`timeout 1s lc3sim -s testFiles/test1 | grep -oP "R6=x[0-9]*" | tail -1`
echo "$q1" >> grade.txt
echo "" >> grade.txt
echo "Test Input 27: R6 should be 1 for full points" >> grade.txt
q2=`timeout 1s lc3sim -s testFiles/test2 | grep -oP "R6=x[0-9]*" | tail -1`
echo "$q2" >> grade.txt
echo "" >> grade.txt
echo "Test Input 25: R6 should be 1 for full points" >> grade.txt
q3=`timeout 1s lc3sim -s testFiles/test3 | grep -oP "R6=x[0-9]*" | tail -1`
echo "$q3" >> grade.txt
echo "" >> grade.txt
echo "Test Input 900: R6 should be 1 for full points" >> grade.txt
q4=`timeout 1s lc3sim -s testFiles/test4 | grep -oP "R6=x[0-9]*" | tail -1`
echo "$q4" >> grade.txt
echo "" >> grade.txt
echo "Test Input 210: R6 should not be 1 for full points" >> grade.txt
q5=`timeout 1s lc3sim -s testFiles/test5 | grep -oP "R6=x[0-9]*" | tail -1`
echo "$q5" >> grade.txt
echo "" >> grade.txt
echo "Test Input 41: R6 should not be 1 for full points" >> grade.txt
q6=`timeout 1s lc3sim -s testFiles/test6 | grep -oP "R6=x[0-9]*" | tail -1`
echo "$q6" >> grade.txt
echo "" >> grade.txt

score=0
if [ "$q1"  == "R6=x0001" ]; then
((score=score+5))
fi
if [ "$q2"  == "R6=x0001" ]; then
((score+=5))
fi
if [ "$q3"  == "R6=x0001" ]; then
((score+=5))
fi
if [ "$q4" == "R6=x0000" ] && [ "$q5" == "R6=x0000" ] &&  [ "$q6" == "R6=x0000" ]; then
score=0
fi

if [ "$q4" == "R6=x0001"  ] && [ "$q5" == "R6=x0001" ] && [ "$q6" == "R6=x0001" ]; then
score="MANUALCHECK"
fi


echo "Partial Score now:" >> grade.txt
echo $score >> grade.txt

if [ "$score" == "MANUALCHECK" ]; then
score=0
fi
#look for .ORIG x3000
sed -i 's/.ORIG/ECEGRADE .FILL /g' gradeprime.asm

echo ".ORIG x3000" > changedprime.asm
echo "JSR DIVIDE" >> changedprime.asm
echo "ADD R3,R0,#0" >> changedprime.asm
echo "ADD R4,R1,#0" >> changedprime.asm
echo "HALT" >> changedprime.asm

cat gradeprime.asm >> changedprime.asm
#

lc3as changedprime.asm >> grade.txt
echo "Test Input 30/10: R3 should be 3 and R4 should be 0 for full points" >> grade.txt
q7=`timeout 1s lc3sim -s testFiles/test7 | grep -oP "R3=x[0-9]* R4=x[0-9]*" | tail -1`
echo "$q7" >> grade.txt
echo "Test Input 100/15: R3 should be 6 and R4 should be A for full points" >> grade.txt
q8=`timeout 1s lc3sim -s testFiles/test8 | grep -oP "R3=x[0-9]* R4=x[A-Z0-9]*" | tail -1`
echo "$q8" >> grade.txt
echo "Test Input 148/35: R3 should be 4 and R4 should be 8 for full points" >> grade.txt
q9=`timeout 1s lc3sim -s testFiles/test9 | grep -oP "R3=x[0-9]* R4=x[0-9]*" | tail -1`
echo "$q9" >> grade.txt

divScore=0
if [ "$q7" == "R3=x0003 R4=x0000" ]  && [ "$q8" == "R3=x0006 R4=x000A" ] && [ "$q9" == "R3=x0004 R4=x0008" ]; then

divScore=15 

fi
echo "Partial score for divide subroutine:" >> grade.txt
echo $divScore >> grade.txt

((fullscore=divScore+score))
#Numbers
echo "Grade:" >> grade.txt
echo "******" >> grade.txt
echo "Functionality: $fullscore" >> grade.txt

pwd >> ../../../Prob2NetidList
if [ "$score" != "MANUALCHECK" ]; then
echo ",$fullscore" >> ../../../Prob2NetidList
else
echo "," >> ../../../Prob2NetidList
fi
