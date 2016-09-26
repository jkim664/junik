#include <stdio.h>
#include "prime.h"

int is_prime(int n);

int main(){
  // Write the code to take a number n from user and print all the prime numbers between 1 and n
	int n, i;

	printf("Enter the value of n:");
	scanf("%d", &n);
	printf("Printing primes less than or equal to %d: \n", n);

	for(i = 2; i <= n; i++)
	{	
		
		if(is_prime (i) == 1)
			printf("%d", i);
		
	}		

	printf("\n"); 
 	 return 0;
}

