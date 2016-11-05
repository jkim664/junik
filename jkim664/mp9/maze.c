#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "maze.h"

//this code first reads a file, then prints the given maze. Then, through a maze solving algorithm, it attempts
//to solve the maze, going from start to finish. Out of the four choices (up down left right) it calculates the 
//manhattan distance and chooses the direction with the least distance from the current position and the endpoint.

maze_t * createMaze(char * fileName)
{
    // Your code here. Make sure to replace following line with your own code.

	maze_t * maze = (maze_t*) malloc(sizeof(maze_t));

	FILE * mazef;	

	int height, width, i, j;
	char lines[1];
	
	mazef = fopen(fileName, "r");		//open file!


	fscanf(mazef, "%d%d", &height, &width);		//scan height and width 
	maze->height = height;
	maze->width = width;

	maze->cells = malloc(sizeof(char*) * height);		//allocate memory for the maze 
	for(i = 0; i < height; i++)
	{
		maze->cells[i] = malloc(sizeof(char*) * width);
	}

	for(i = 0; i < height; i++)			//create maze line by line	
	{
		for(j = 0; j < width + 1; j++)
		{	
			fscanf(mazef, "%c", lines);
			if(lines[0] != '\n')
			{
				maze->cells[i][j] = lines[0];
				if(lines[0] == START)		//if start is found, store cell location 
				{
					maze->startColumn = j;
					maze->startRow = i;
				}
				if(lines[0] == END)		//if end is found, store cell location
				{
					maze->endColumn = j;
					maze->endRow = i;
				}
			}
		}
	}




  return maze;
}

/*
 * destroyMaze -- Frees all memory associated with the maze structure, including the structure itself
 * INPUTS:        maze -- pointer to maze structure that contains all necessary information
 * OUTPUTS:       None
 * RETURN:        None
 * SIDE EFFECTS:  All memory that has been allocated for the maze is freed
 */
void destroyMaze(maze_t * maze)
{

	free(maze->cells);			//free the memoryy
	free(maze);


}

/*
 * printMaze --  Prints out the maze in a human readable format (should look like examples)
 * INPUTS:       maze -- pointer to maze structure that contains all necessary information
 *               width -- width of the maze
 *               height -- height of the maze
 * OUTPUTS:      None
 * RETURN:       None
 * SIDE EFFECTS: Prints the maze to the console
 */
void printMaze(maze_t * maze)
{
  	printf("%d %d\n", maze->height, maze->width);
	int i, j;
	for(i = 0; i < maze->height; i++)
	{
		for(j = 0; j < maze->width + 1; j++)
		{
			printf("%c", maze->cells[i][j]);	//print character by character
		}

		printf("\n");
	}
}

/*
 * solveMazeManhattanDFS -- recursively solves the maze using depth first search and a manhattan distance heuristic
 * INPUTS:               maze -- pointer to maze structure with all necessary maze information
 *                       col -- the column of the cell currently beinging visited within the maze
 *                       row -- the row of the cell currently being visited within the maze
 * OUTPUTS:              None
 * RETURNS:              0 if the maze is unsolvable, 1 if it is solved
 * SIDE EFFECTS:         Marks maze cells as visited or part of the solution path
 */
int solveMazeManhattanDFS(maze_t * maze, int col, int row)
{
    // Your code here. Make sure to replace following line with your own code.

	if(col > maze->width || row >= maze->height || col < 0 || row < 0) //check bounds
	return 0;

	else if(maze->cells[row][col] == PATH || maze->cells[row][col] == WALL || maze->cells[row][col] == VISITED) //check if current place is a wall, a path, or a visited place
	return 0;
 	
	else if(maze->cells[row - 1][col] == END || maze->cells[row + 1][col] == END || maze->cells[row][col - 1] == END || maze->cells[row][col + 1] == END) //check if END is around
	{
	maze->cells[row][col] = PATH;	
	return 1;
	}
	

	float mup, mdown, mleft, mright;		//manhattan values

	mup = fabs(col - maze->endColumn) + fabs(row - 1 - maze->endRow);
	mdown = fabs(col - maze->endColumn) + fabs(row + 1 - maze->endRow);
	mleft = fabs(col - 1 - maze->endColumn) + fabs(row - maze->endRow);
	mright = fabs(col + 1 - maze->endColumn) + fabs(row - maze->endRow);

	int mand[4];			//cast as integer
	mand[0] = (int)mup;
	mand[1] = (int)mdown;
	mand[2] = (int)mleft;
	mand[3] = (int)mright;

	int check0, check1, check2, check3; 	//for checking purposes
	check0 = (int)mup;
	check1 = (int)mdown;
	check2 = (int)mleft;
	check3 = (int)mright;

	int i, c, temp;

	for(i = 0; i < 3; i++)		//sort values from least to greatest
	{
		for(c = i + 1; c < 3; c++)
		{
			if(mand[c] < mand[i])
			{
				temp = mand[i];
				mand[i] = mand[c];
				mand[c] = temp;
			}
		}
	}
	

	if(maze->cells[row][col] != START)		//if the cell is not START, mark as PATH
	{
		maze->cells[row][col] = PATH;
	}

	for(i = 0; i < 4; i++)
	{
		if(mand[i] == check0)			//if up is next choice of moving
			{
				if(solveMazeManhattanDFS(maze, col, row - 1) == 1)
				{
					return 1;
				}
			}

		if(mand[i] == check1)			//if down
			{
				if(solveMazeManhattanDFS(maze, col, row + 1) == 1)
				{
					return 1;
				}
			}

		if(mand[i] == check2)			//if left
			{
				if(solveMazeManhattanDFS(maze, col - 1, row) == 1)
				{
					return 1;
				}
			}

		if(mand[i] == check3)			//if right
			{
				if(solveMazeManhattanDFS(maze, col + 1, row) == 1)
				{
					return 1;
				}
			}

	}

	maze->cells[row][col] = VISITED;		//if nothing happens in the loop, check the cell as visited

	return 0;  
}
