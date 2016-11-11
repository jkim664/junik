# Compile the program
gcc -O2 recursive_sum.c -o recursive_sum

# Run the program with testcase test.txt and direct the output to result.txt
timeout 3 ./recursive_sum < test.txt > result.txt

# Compare result.txt with golden result result.txt
diff gold.txt result.txt
