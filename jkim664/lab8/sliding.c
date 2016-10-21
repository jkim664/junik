#include "sliding.h"
/*  Slide all values of array up
*/
void slide_up(int* my_array, int rows, int cols){

int i, j, c;

	for(j = 0; j < cols; j++)
	{
		for(i = 0; i < rows ; i++)
		{
			if(my_array[i * cols + j] != -1)
			{		
				for(c = 0; c < i; c++)
				{
					if(my_array[c * cols + j] == -1)
					{
						my_array[c * cols + j] = my_array[i * cols + j];
						my_array[i * cols + j] = -1;
					}	
				}	
			}
		}
	}




    return;
}
