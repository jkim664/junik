/* Function matrix_multiply
 * matrixA, matrixB, and matrix C are matrices represented as
 * one-dimensional arrays in row-major order. This function must
 * preform matrix multiplication so that C=A*B. 
 * INPUT: matrixA, a one dimensional array of size m*k
 *        matrixB, a one dimensional double array of size k*n
 * OUTPUT: matrixC, a one dimensional double array of size m*n
 */
#include "matrix.h"
void matrix_multiply(double *matrixA,double *matrixB,double *matrixC,int m,int k,int n)
{
//YOUR CODE HERE
	int i, j, l;
		for(i = 0; i < k; i++)
		{
			for(j = 0; j < n ; j++)
			{
				double curr = 0, new = 0;
				for(l = 0; l < k ; l++)			
				{	
					curr = new;
					new = matrixA[i*k + l] * matrixB[l*n + j] + curr;
				}
		
			matrixC[i*n + j] = new;				

			}

		}	
}		

