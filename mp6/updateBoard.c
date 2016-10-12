/*
 * countLiveNeighbor
 * Inputs:
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * row: the row of the cell that needs to count alive neighbors.
 * col: the col of the cell that needs to count alive neighbors.
 * Output:
 * return the number of alive neighbors. There are at most eight neighbors.
 * Pay attention for the edge and corner cells, they have less neighbors.
 */


// the function countliveneighbor first checks if the position is in a corner, then edge, then the middle. Accordingly, this function checks around the position and checks if there are 1's around. It returns the value of 1's around the position. 

int countLiveNeighbor(int* board, int boardRowSize, int boardColSize, int row, int col){

int pos = row * boardColSize + col;
int alive = 0;

if((row == 0 && col == 0) || (row == 0 && col == boardColSize - 1) || (row == boardRowSize - 1 && col == 0) || (row == boardRowSize - 1 && col == boardColSize - 1))
{								//check to see if corners
	if(row == 0 && col == 0)
	{
		if(board[pos + 1] == 1)
		alive++;
		if(board[pos + boardColSize] == 1)
		alive++;
		if(board[pos + boardColSize + 1] == 1)
		alive++;
	}
	else if(row == 0 && col == boardColSize - 1)
	{
		if(board[pos - 1] == 1)
		alive++; 
		if(board[pos + boardColSize] == 1)
		alive++;
		if(board[pos + boardColSize - 1] == 1)	
		alive++;
	}
	else if(row == boardRowSize - 1 && col == 0)
	{
		if(board[pos + 1] == 1)
		alive++; 
		if(board[pos - boardColSize] == 1)
		alive++;
		if(board[pos - boardColSize + 1] == 1)	
		alive++;
	}
	else if(row == boardRowSize - 1 && col == boardColSize - 1)
	{
		if(board[pos - 1] == 1)
		alive++; 
		if(board[pos - boardColSize] == 1)
		alive++;
		if(board[pos - boardColSize - 1] == 1)	
		alive++;
	}
}
else if(row == 0 || row == boardRowSize - 1 || col == 0 || col == boardColSize - 1) //check to see if edges
{
	if(row == 0)
	{
		if(board[pos - 1] == 1)
		alive++;
		if(board[pos + 1] == 1)
		alive++;
		if(board[pos + boardColSize] == 1)
		alive++;
		if(board[pos + boardColSize + 1] == 1)
		alive++;
		if(board[pos + boardColSize - 1] == 1)
		alive++;
	}

	else if(row == boardRowSize - 1)
	{
		if(board[pos - 1] == 1)
		alive++;
		if(board[pos + 1] == 1)
		alive++;
		if(board[pos - boardColSize] == 1)
		alive++;
		if(board[pos - boardColSize + 1] == 1)
		alive++;
		if(board[pos - boardColSize - 1] == 1)
		alive++;
	}
	
	else if(col == 0)
	{
		if(board[pos + 1] == 1)
		alive++;
		if(board[pos + boardColSize] == 1)
		alive++;
		if(board[pos - boardColSize] == 1)
		alive++;
		if(board[pos + boardColSize + 1] == 1)
		alive++;
		if(board[pos - boardColSize + 1] == 1)
		alive++;
	}

	else if(col == boardColSize - 1)
	{
		if(board[pos - 1] == 1)
		alive++;
		if(board[pos + boardColSize] == 1)
		alive++;
		if(board[pos - boardColSize] == 1)
		alive++;
		if(board[pos + boardColSize - 1] == 1)
		alive++;
		if(board[pos - boardColSize - 1] == 1)
		alive++;
	}
}
	else								//if neither edge or corner, check all surrounding
	{
		if(board[pos - 1] == 1)
		alive++;
		if(board[pos + 1] == 1)
		alive++;
		if(board[pos + boardColSize] == 1)
		alive++;
		if(board[pos - boardColSize] == 1)
		alive++;
		if(board[pos + boardColSize + 1] == 1)
		alive++;
		if(board[pos + boardColSize - 1] == 1)
		alive++;
		if(board[pos - boardColSize + 1] == 1)
		alive++;
		if(board[pos - boardColSize - 1] == 1)
		alive++;
	}

	return alive;				//return the value of alive cells 
}
/*
 * Update the game board to the next step.
 * Input: 
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: board is updated with new values for next step.
 */
void updateBoard(int* board, int boardRowSize, int boardColSize) {

int newboard[boardRowSize * boardColSize - 1];			//a temporary board to store the next state values in
int row, col, pos, i, alive;
for(i = 0; i < boardRowSize * boardColSize - 1; i++)
{
	row = i / boardColSize;
	col = i % boardColSize;
	pos = row * boardColSize + col;
	alive = countLiveNeighbor(board, boardRowSize, boardColSize, row, col);		//get the number of alive values for each cell
	if(board[pos] == 1)								
	{
		if(alive < 2 || alive > 3)						//if the cell is alive and has less than 2 or more than 3 alive cells, then the 
		newboard[pos] = 0;							//value of the specific position becomes zero
		else
		newboard[pos] = 1;
	}
	else
	{
		if(alive == 3)								//if the cell is dead and exactly has 3 alive cells, the value changes to one
		newboard[pos] = 1;
		else
		newboard[pos] = 0;
	}
}

for(i = 0; i < boardRowSize * boardColSize - 1; i++)					//tranferring the new values of the cells to the current board
{
	row = i / boardColSize;
	col = i % boardColSize;
	pos = row * boardColSize + col;
	board[pos] = newboard[pos];
}

}

/*
 * aliveStable
 * Checks if the alive cells stay the same for next step
 * board: 1-D array of the current game board. 1 represents a live cell.
 * 0 represents a dead cell
 * boardRowSize: the number of rows on the game board.
 * boardColSize: the number of cols on the game board.
 * Output: return 1 if the alive cells for next step is exactly the same with 
 * current step or there is no alive cells at all.
 * return 0 if the alive cells change for the next step.
 */ 
int aliveStable(int* board, int boardRowSize, int boardColSize){

int newboard[boardRowSize * boardColSize - 1];							//from here, it is the same code as the function updateBoard
int row, col, pos, i, alive;
for(i = 0; i < boardRowSize * boardColSize - 1; i++)
{
	row = i / boardColSize;
	col = i % boardColSize;
	pos = row * boardColSize + col;
	alive = countLiveNeighbor(board, boardRowSize, boardColSize, row, col);
	if(board[pos] == 1)
	{
		if(alive < 2 || alive > 3)
		newboard[pos] = 0;
		else
		newboard[pos] = 1;
	}
	else
	{
		if(alive == 3)
		newboard[pos] = 1;
		else
		newboard[pos] = 0;
	}
}

for(i = 0; i < boardRowSize * boardColSize - 1; i++)					//if the current board values are different from the new board values, then
{											//return 0
	row = i / boardColSize;
	col = i % boardColSize;
	pos = row * boardColSize + col;
	if(board[pos] == 1 && newboard[pos] != 1)
	return 0;
}
return 1; 										//if nothing changed, then return 1

}

				
				
			

