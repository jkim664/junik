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
	int m=4,n=3,k=3;
	int A[12] =
	{8   ,  2   ,  4,
		3    , 2   ,  6,
			7  ,   5  ,   3,
			7   , 10  ,   8};		 


	//B1 (3x4)
	int B[9] =
	{ 1  ,   3   ,  5,
		5   ,  3  ,   2,
			5   ,  2  ,   1};


	int C[12];
	int Cg[12];
	mul_matrix_golden(A,B,Cg,m,n,k);
	mul_matrix(A,B,C,m,n,k);
	for(int i=0;i<m*n;i++)
	{
		if(C[i]!=Cg[i])
		{
			return 0;
		}
	}	
	printf("Correct\n");
	
}
