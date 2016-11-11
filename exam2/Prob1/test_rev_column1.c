#include <stdio.h>
#include "matrix.h"

int main()
{
  int A[16] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
  int Arev[16] = {4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1};
  int arow = 4;
  int acol = 4;

  int outA[16];

  reverse_column(A, arow, acol, outA);

  // test case 1
  int pass = 1;
  int i;
  for(i=0; i<16; i++){
    if(outA[i] != Arev[i])
      pass = 0;
  }

  if(pass == 1)
    printf("Correct\n");

  return 0;
}
