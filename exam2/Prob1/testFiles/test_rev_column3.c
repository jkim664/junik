#include <stdio.h>
#include "matrix.h"

int main()
{
  int C[1] = {42};
  int Crev[1] = {42};
  int crow = 1;
  int ccol = 1;

  int outC[1];

  reverse_column(C, crow, ccol, outC);

  // test case 3
  int pass = 1;
  int i;
  for(i=0; i<1; i++){
    if(outC[i] != Crev[i])
      pass = 0;
  }

  if(pass == 1)
    printf("Correct\n");

  return 0;
}
