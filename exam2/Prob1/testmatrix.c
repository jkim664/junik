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
	//4x3, 3x4 = 4x4
	//4x4, 4x3 = 4x3
    int m1 = 4, n1 = 4, k1 = 3;
    int m2 = 4, n2 = 3, k2 = 4;
	//declare matrices
    int matrix_A1[12] = {-1, 3, 4, 
                         -2, 8, 9, 
                         10, 1, -1, 
                          8, 7, 3};
    int matrix_A1_out[12];

    int n_rows_A1=4, n_cols_A1=3;
    int matrix_A2[16] ={1, 2, 3, 4,
                        6, 7, 8, 9,
                        11,12,13,14,
                        16,17,18,19};
    int n_rows_A2=4, n_cols_A2=4;
    int matrix_A2_out[16];

    //B1 (3x4)
    int matrix_B1[12] ={2, -3, 5, 6, 
	       	        8, 10, 9, 1, 
		       -2, 3, 2, 4};
	//B2 (4X3)
    int matrix_B2[12] = {-2, 1, 4,
                         8, 1, 3, 
                         2, 6, 1,
                         -9, 2, 3};

    int matrix_C1[16];
    int matrix_C2[12];

    //Call functions, first Matrix Mult.
    printf("*****Testing mul_matrix*****\n");
    printf("Test 1\n"); //matrix_A1*matrix_B1
    mul_matrix(matrix_A1,matrix_B1,matrix_C1,m1,n1,k1);
    printf("C_matrix: \n");
    print_matrix(matrix_C1, m1,n1);
    
    printf("Test 2\n"); //matrix_A1*matrix_B1
    mul_matrix(matrix_A2,matrix_B2,matrix_C2,m2,n2,k2);
    printf("C_matrix: \n");
    print_matrix(matrix_C2, m2,n2);
    

 
    //Reverse_Column
    printf("*****Testing reverse_column*****\n");

    printf("Test 1\n");
    printf("in_matrix before: \n");//matrix_A1
    print_matrix(matrix_A1, n_rows_A1, n_cols_A1);
    
    reverse_column(matrix_A1,n_rows_A1,n_cols_A1, matrix_A1_out);
    printf("out_matrix after: \n");
    print_matrix(matrix_A1_out, n_rows_A1, n_cols_A1);


    printf("Test 2\n");
    printf("in_matrix before: \n");//matrix_A2
    print_matrix(matrix_A2, n_rows_A2, n_cols_A2);
    
    reverse_column(matrix_A2,n_rows_A2,n_cols_A2, matrix_A2_out);
    printf("out_matrix after: \n");
    print_matrix(matrix_A2_out, n_rows_A2, n_cols_A2);
}
