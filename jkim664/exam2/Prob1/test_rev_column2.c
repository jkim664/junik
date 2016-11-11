#include <stdio.h>
#include "matrix.h"

int main()
{
  int B[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  int Brev[15] = {4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 14, 13, 12, 11, 10};
  int brow = 3;
  int bcol = 5;

  int outB[15];

  reverse_column(B, brow, bcol, outB);


  // test case 2
  int pass = 1;
  int i;
  for(i=0; i<15; i++){
    if(outB[i] != Brev[i])
      pass = 0;
  }

  if(pass == 1)
    printf("Correct\n");

  return 0;
}
