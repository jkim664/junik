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
	int m=6,n=6,k=6;
	int A[36] =
	{  5  ,   3   ,  4   ,  5  ,   1   ,  4 ,
		5   ,  5   ,  3   ,  1  ,   2   ,  2,
		1    , 3   ,  4   ,  1  ,   3   ,  1,
		4    , 5   ,  4   ,  3  ,   5   ,  3,
		2    , 2   ,  1   ,  5  ,   1   ,  3,
		3    , 4   ,  1   ,  4  ,   5   ,  1};

	//B1 (3x4)
	int B[36] =
	{ 3,     4,     3  ,   3   ,  3    , 4,
		2 ,    2,     1   ,  1   ,  1    , 1,
		2 ,    5,     5   ,  3   ,  3    , 1,
		3 ,    5,     5   ,  2   ,  3     ,2,
		2 ,    4 ,    5    , 1   ,  4     ,3,
		2  ,   2 ,    2    , 1    , 4    , 4};
	int C[36];
	int Cg[36];
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
