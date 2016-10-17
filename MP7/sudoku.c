#include "sudoku.h"

// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}

//-------------------------------------------------------------------------------------------------
// Start coding your MP here.
// ------------------------------------------------------------------------------------------------


//introduction
//This code checks individual cell and sees what number can be put in the array so that
//no same number is in the row,  column, or the 3x3 matrix it is already in. 
//After checking the validity of the number at the array cell, this code keeps filling in the next available array cell and 
//When the array as no 0's, the function prints the 2D array. 



// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

  assert(i>=0 && i<9);

  // BEG TODO
  
	int j;
	for(j = 0; j < 9; j++)
	{
		if(val == sudoku[i][j])			//if the value is equal to any of the numbers in the row, return true;
		return 1;
	} 	


  return 0;
  // END TODO
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

  assert(j>=0 && j<9);

  // BEG TODO
  
	int i;
	for(i = 0; i < 9; i++)
	{
		if(val == sudoku[i][j])		//if the value is equal to any of the numbers in the column, return true;
		return 1;
	}


  return 0;
  // END TODO
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
  assert(i>=0 && i<9);
  
  // BEG TODO
	int a, b;
  
	if(i < 3 && j < 3)				//the top left 3x3 
	{
		for(a = 0; a < 3; a++)
		{
			for(b = 0; b < 3; b++)
			{
				if(val == sudoku[a][b])
				return 1;
			}
		}
	}
 
	else if(i < 3 && j > 2 && j < 6)		//the top middle 3x3
	{
		for(a = 0; a < 3; a++)
		{
			for(b = 3; b < 6; b++)
			{
				if(val == sudoku[a][b])
				return 1;
			}
		}
	}

	else if(i < 3 && j > 5 && j < 9)		//the top right 3x3
	{
		for(a = 0; a < 3; a++)
		{
			for(b = 6; b < 9; b++)
			{
				if(val == sudoku[a][b])
				return 1;
			}
		}
	}

	else if(i > 2 && i < 6 && j < 3)		// the middle left 3x3
	{
		for(a = 3; a < 6; a++)
		{
			for(b = 0; b < 3; b++)
			{
				if(val == sudoku[a][b])
				return 1;
			}
		}
	}
	else if(i > 2 && i < 6 && j > 2 && j < 6)	//the middle 3x3
	{
		for(a = 3; a < 6; a++)
		{
			for(b = 3; b < 6; b++)
			{
				if(val == sudoku[a][b])
				return 1;
			}
		}
	}

	else if(i > 2 && i < 6 && j > 5 && j < 9)	//the middle right 3x3
	{
		for(a = 3; a < 6; a++)
		{
			for(b = 6; b < 9; b++)
			{
				if(val == sudoku[a][b])
				return 1;
			}
		}
	}

	else if(i > 5 && i < 9 && j < 3)		//the bottom left 3x3
	{
		for(a = 6; a < 9; a++)
		{
			for(b = 0; b < 3; b++)
			{
				if(val == sudoku[a][b])
				return 1;
			}
		}
	}
	else if(i > 5 && i < 9 && j > 2 && j < 6)	//the bottom middle 3x3
	{
		for(a = 6; a < 9; a++)
		{
			for(b = 3; b < 6; b++)
			{
				if(val == sudoku[a][b])
				return 1;
			}
		}
	}

	else if(i > 5 && i < 9 && j > 5 && j < 9)	//the bottom right 3x3
	{
		for(a = 6; a < 9; a++)
		{
			for(b = 6; b < 9; b++)
			{
				if(val == sudoku[a][b])
				return 1;
			}
		}
	}
 return 0;
  // END TODO
}

// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {
  if(is_val_in_row(val, i, sudoku)) return 0;
  if(is_val_in_col(val, j, sudoku)) return 0;
  if(is_val_in_3x3_zone(val, i, j, sudoku)) return 0;
  return 1;
}

int cell_check(int* i, int* j, const int sudoku[9][9])		//I implemented this function just for the sake of organization. This function's inputs are 
{								//the sudoku board and the addresses of the row and column. It finds the next available empty
								//cell then stores the addresses into memory of i and j. If there are no available cells, then
	int row, col;						//that means the sudoku board has been completed, and it returns 1. 
	for(row = 0; row < 9; row++)
	{
		for(col = 0; col < 9; col++)
		{
			if(sudoku[row][col] == 0)
			{
				*i = row;
				*j = col;
				return 0;
			}
		}
	}
	return 1;
	
}

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {

  // BEG TODO.		
	int i, j;
	
	if(cell_check(&i, &j, sudoku) == 1)		//check if the sudoku board is all filled out
		return 1;

	else
	{
		for(int val = 1; val <= 9; val++)	
		{
			if(is_val_valid(val, i, j, sudoku) == 1) 	//if the board is not full, check if a value can be input into the cell.
			{	
				sudoku[i][j] = val;			//if valid, insert the value into the cell.
				if(solve_sudoku(sudoku) == 1)		//solve the board with this value in place of the cell.
				{		
					return 1;
				}
				sudoku[i][j] = 0;			//if not solvable with this value in the cell, try next value++.
			}
		}	
	}	
				



  return 0;
  // END TODO.
}



