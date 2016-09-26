#include "prime.h"

int is_prime(int n){
  // Return 1 if n is a prime, and 0 if it is not
	int j;
	for(j = 2; j < n; j++)
	{
		if(n % j == 0)
		{
			return 0;
		}			

	}	

  return 1;
}

