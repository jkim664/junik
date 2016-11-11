
// Input:
// A_matrix: pointer to an array containing the values of a matrix with m rows, k columns (stored in row-major order),
// B_matrix: pointer to an array containing the values of a matrix with k rows and n columns (stored in row-major order)
// C_matrix: pointer to an array containing the values of a matrix with m rows and n columns (stored in row-major order) 
// m, n, k: matrix dimensions m>0, n>0m k>0
// Space for matrix C is already allocated. You may assume m, n and k are >0. 
// Return: None
// Output: C=A*B

void mul_matrix_golden(int* A_matrix, int* B_matrix, int* C_matrix, int m, int n, int k)
{
	//Your code here
	int i,j,l;
	for(i=0; i<m; ++i)
		for(j=0; j<n; ++j)
		{
			C_matrix[i*n+j]=0;
			for(l=0; l<k; ++l)
			{
				C_matrix[i*n+j]+=A_matrix[i*k+ l]*B_matrix[l*n+j];
			}
		}
}


// This function reverses the order of the columns of in_matrix and stores the result in out_matrix (the space for out_matrix is already allocated)
// The first column in in_matrix should become the last column of out_matrix
// the second to last column of in_matrix should become the second column of 
// out_matrix, and so on. 
//  in_matrix: pointer to an array containing the value of a matrix with n_rows rows and n_cols columns, in row major order
//  n_rows: the number of rows in the matrix, assume>0
//  n_cols: the number of columns in the matrix, assume>0
//  out_matrix: pointer to an array containing the values of a matrix with n_row rows and n_cols columns, in row major order
//  Return: None
void reverse_column_golden(int* in_matrix, int n_rows, int n_cols, int * out_matrix)
{
	//Your code here
	int i,j;
	for(i=0;i<n_rows;i++){
		for(j=0;j<n_cols;j++){
			out_matrix[i*n_cols+(-j+n_cols-1)]=
				in_matrix[i*n_cols+j];
		}
	}

}
