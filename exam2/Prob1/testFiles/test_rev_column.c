#include <stdio.h>
#include "matrix.h"

int main()
{
  int A[16] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
  int B[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  int C[1] = {42};
  int Arev[16] = {4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1, 4, 3, 2, 1};
  int Brev[15] = {4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 14, 13, 12, 11, 10};
  int Crev[1] = {42};
  int arow = 4;
  int acol = 4;
  int brow = 3;
  int bcol = 5;
  int crow = 1;
  int ccol = 1;

  int outA[16];
  int outB[15];
  int outC[1];

  reverse_column(A, arow, acol, outA);
  reverse_column(B, brow, bcol, outB);
  reverse_column(C, crow, ccol, outC);

  // test case 1
  int pass = 1;
  int i;
  for(i=0; i<16; i++){
    if(outA[i] != Arev[i])
      pass = 0;
  }

  if(pass == 1)
    printf("Correct\n");

  // test case 2
  pass = 1;
  for(i=0; i<15; i++){
    if(outB[i] != Brev[i])
      pass = 0;
  }

  if(pass == 1)
    printf("Correct\n");

  // test case 3
  pass = 1;
  for(i=0; i<1; i++){
    if(outC[i] != Crev[i])
      pass = 0;
  }

  if(pass == 1)
    printf("Correct\n");

  return 0;
}
