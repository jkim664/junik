/*Includes code to test each function.
  Expected output is in gold output files.
  This file can be modified for further testing.*/
#include <stdio.h>
#include "matrix.h"

void print_matrix(int * matrix_A, int n_rows, int n_cols)
{
	int i,j;
	for(i=0;i<(n_rows);i++){
		for(j=0;j<(n_cols);j++){
			printf("%d ",matrix_A[i*n_cols+j]);
		}
		printf("\n");
	}
}
int main()
{
	int m=6,n=3,k=1;
	int A[6] =
		    { 4,
			         5,
				      2,
				           4,
					        4,
						     1};
	int B[3] = {3 ,    4,     2};
	int C[18];
	int Cg[18];
	mul_matrix_golden(A,B,Cg,m,n,k);
	mul_matrix(A,B,C,m,n,k);
	//C[10]=0;
	for(int i=0;i<m*n;i++)
	{
		if(C[i]!=Cg[i])
		{
			return 0;
		}
	}	
	printf("Correct\n");

}
