#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>

int s(int x) {

int numb1, numb2;

	while( x > 0 )
	{
		numb1 = x % 10;
		numb2 = numb2 + numb1;
		x = x / 10;
	}	
	return numb2;

}

int recursive_sum(int x) {
	if(x < 10)
	return x;
	
	else
	{
		return recursive_sum(s(x));
	}


}

// Function: main
int main(int argc, char** argv) {

  int x;
  while(scanf("%d", &x) == 1) {
    printf("%d\n", recursive_sum(x));
  }

  return 1;
}


