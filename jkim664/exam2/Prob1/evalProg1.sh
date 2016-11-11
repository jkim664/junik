#!/bin/bash

#Example grading script

late_points=$1

cp testFiles/* ./
#Compilation
echo "Compilation Results:" > grade.txt
gcc -Wall -g -std=c99 multc1.c matrix.c matrixg.c -o test1 >> grade.txt
gcc -Wall -g -std=c99 multc2.c matrix.c matrixg.c -o test2 >> grade.txt
gcc -Wall -g -std=c99 multc3.c matrix.c matrixg.c -o test3 >> grade.txt
gcc -Wall -g -std=c99 test_rev_column1.c matrix.c -o test4 >> grade.txt
gcc -Wall -g -std=c99 test_rev_column2.c matrix.c -o test5 >> grade.txt
gcc -Wall -g -std=c99 test_rev_column3.c matrix.c -o test6 >> grade.txt
echo "********************" >> grade.txt
echo "" >> grade.txt

echo "Test 1: 4 by 3 multiply 3 by 3" >> grade.txt
q1=`timeout 1 ./test1`
echo "$q1" >> grade.txt
echo "" >> grade.txt
echo "Test 2: 6 by 6 multiply 6 by 6" >> grade.txt
q2=`timeout 1 ./test2`
echo "$q2" >> grade.txt
echo "" >> grade.txt
echo "Test 3: 6 by 1 multiply 1 by 3" >> grade.txt
q3=`timeout 1 ./test3`
echo "$q3" >> grade.txt
echo "" >> grade.txt
echo "Test 4: Matrix Reverse 4 by 4">> grade.txt
q4=`timeout 1 ./test4`
echo "$q4" >> grade.txt
echo "" >> grade.txt
echo "Test 5: Matrix Reverse 3 by 5" >> grade.txt
q5=`timeout 1 ./test5`
echo "$q5" >> grade.txt
echo "" >> grade.txt
echo "Test 6: Matrix Reverse 1 by 1" >> grade.txt
q6=`timeout 1 ./test6`
echo "$q6" >> grade.txt
echo "" >> grade.txt

score=0
if [ "$q1"  == "Correct" ]; then
((score=score+5))
fi
if [ "$q2"  == "Correct" ]; then
((score+=5))
fi
if [ "$q3"  == "Correct" ]; then
((score+=5))
fi
if [ "$q4"  == "Correct" ]; then
((score+=5))
fi
if [ "$q5"  == "Correct" ]; then
((score+=5))
fi
if [ "$q6"  == "Correct" ]; then
((score+=5))
fi
#Numbers
echo "Grade:" >> grade.txt
echo "******" >> grade.txt
echo "Functionality: $score" >> grade.txt

pwd >> ../../../Prob2NetidList
if [ "$score" != "MANUALCHECK" ]; then
echo ",$fullscore" >> ../../../Prob2NetidList
else
echo "," >> ../../../Prob2NetidList
fi
