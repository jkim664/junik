/*			
 *
 * prog5.c - source file adapted from UIUC ECE198KL Spring 2013 Program 4
 *           student code -- GOLD VERSION by Steven S. Lumetta
 */


/*
 * The functions that you must write are defined in the header file.
 * Blank function prototypes with explanatory headers are provided
 * in this file to help you get started.
 */

//intro paragraph
//this program takes 4 guesses from the user and compares to the randomly generated numbers, then 
//figures out how many perfect matches and mistmatches there are. To do so, the program first figures out
//all the perfect matches first. Then, the it figures out if there are any mismatches by checking 
//if the other three elements have been paired either perfectly or imperfectly. If so, then they are matched.
//at the end the program spits out how many perfect numbers and mistmatches have been made. 





#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "prog5.h"


/*
 * You will need to keep track of the solution code using file scope
 * variables as well as the guess number.
 */

static int guess_number;
static int solution1;
static int solution2;
static int solution3;
static int solution4;


/*
 * set_seed -- This function sets the seed value for pseudorandom
 * number generation based on the number the user types.
 * The input entered by the user is already stored in the string seed_str by the code in main.c.
 * This function should use the function sscanf to find the integer seed value from the 
 * string seed_str, then initialize the random number generator by calling srand with the integer
 * seed value. To be valid, exactly one integer must be entered by the user, anything else is invalid. 
 * INPUTS: seed_str -- a string (array of characters) entered by the user, containing the random seed
 * OUTPUTS: none
 * RETURN VALUE: 0 if the given string is invalid (string contains anything
 *               other than a single integer), or 1 if string is valid (contains one integer)
 * SIDE EFFECTS: initializes pseudo-random number generation using the function srand. Prints "set_seed: invalid seed\n"
 *               if string is invalid. Prints nothing if it is valid.
 */
int
set_seed (const char seed_str[])
{

	int seed;
	char post[2];
	
	if(sscanf(seed_str, "%d%1s", &seed, post) == 1)     //check if sscanf only read 1 value
	{
		srand(seed);					//set seed
    		return 1;
	}
	
	else
		printf("set_seed: invalid seed\n");		// if read more than 2 items, wrong

		
	return 0;
	
}


/*
 * start_game -- This function is called by main.c after set_seed but before the user makes guesses.
 *               This function creates the four solution numbers using the approach
 *               described in the wiki specification (using rand())
 *               The four solution numbers should be stored in the static variables defined above. 
 *               The values at the pointers should also be set to the solution numbers.
 *               The guess_number should be initialized to 1 (to indicate the first guess)
 * INPUTS: none
 * OUTPUTS: *one -- the first solution value (between 0 and 7)
 *          *two -- the second solution value (between 0 and 7)
 *          *three -- the third solution value (between 0 and 7)
 *          *four -- the fourth solution value (between 0 and 7)
 * RETURN VALUE: none
 * SIDE EFFECTS: records the solution in the static solution variables for use by make_guess, set guess_number
 */
void
start_game (int* one, int* two, int* three, int* four)
{
  
	solution1 = rand() % 8;			//generate pseudo random numbers
	solution2 = rand() % 8;
	solution3 = rand() % 8;
	solution4 = rand() % 8;	

	guess_number = 1;			//initialize guess number 

	*one = solution1;
	*two = solution2;
	*three = solution3;
	*four = solution4;
}

/*
 * make_guess -- This function is called by main.c after the user types in a guess.
 *               The guess is stored in the string guess_str. 
 *               The function must calculate the number of perfect and misplaced matches
 *               for a guess, given the solution recorded earlier by start_game
 *               The guess must be valid (contain only 4 integers, within the range 0-7). If it is valid
 *               the number of correct and incorrect matches should be printed, using the following format
 *               "With guess %d, you got %d perfect matches and %d misplaced matches.\n"
 *               If valid, the guess_number should be incremented.
 *               If invalid, the error message "make_guess: invalid guess\n" should be printed and 0 returned.
 *               For an invalid guess, the guess_number is not incremented.
 * INPUTS: guess_str -- a string consisting of the guess typed by the user
 * OUTPUTS: the following are only valid if the function returns 1 (A valid guess)
 *          *one -- the first guess value (between 0 and 7)
 *          *two -- the second guess value (between 0 and 7)
 *          *three -- the third guess value (between 0 and 7)
 *          *four -- the fourth color value (between 0 and 7)
 * RETURN VALUE: 1 if the guess string is valid (the guess contains exactly four
 *               numbers between 0 and 7), or 0 if it is invalid
 * SIDE EFFECTS: prints (using printf) the number of matches found and increments guess_number(valid guess) 
 *               or an error message (invalid guess)
 *               (NOTE: the output format MUST MATCH EXACTLY, check the wiki writeup)
 */
int
make_guess (const char guess_str[], int* one, int* two, 
	    int* three, int* four)
{
	int w, x, y, z, perfmatch = 0, mismatch = 0;
	char post[5];
	bool pairone, pairtwo, pairthree, pairfour, pair11, pair22, pair33, pair44;
	pair11 = false;
	pair22 = false;
	pair33 = false;
	pair44 = false;
	if(sscanf(guess_str, "%d%d%d%d%1s", &w, &x, &y, &z, post) != 4)		//check if sscanf read 4 items
	{
		printf("make_guess: invalid guess\n");
		return 0;
	}
	
	if((w < 0 ) || (w > 7))					//check if read characters are between 0-7
	{
		printf("make_guess: invalid guess\n");
		return 0;
	}

		
	else if((x < 0 ) || (x > 7))
	{
		printf("make_guess: invalid guess\n");
		return 0;
	}

	else if((y < 0 ) || (y > 7))
	{
		printf("make_guess: invalid guess\n");
		return 0;
	}

	else if((z < 0 ) || (z > 7))
	{
		printf("make_guess: invalid guess\n");
		return 0;
	}

	if(w == solution1)					//check if inputs are perfect matches
	{
		perfmatch++;
		pairone = true;
	}
	
	if(x == solution2)
	{	
		perfmatch++;
		pairtwo = true;
	}
	
	if(y == solution3)	
	{
		perfmatch++;
		pairthree = true;
	}
	
	if(z == solution4)
	{	
		perfmatch++;
		pairfour = true;
	}
	
	if(pairone == false)				//check if there are any mismatches
	{
		if(pair22 == false && pairtwo == false && w == solution2) 
		{
			mismatch++;
			pair22 = true;
		}
		else if(pair33 == false && pairthree == false && w == solution3)
		{
			mismatch++;
			pair33 = true;
		}

		else if(pair44 == false && pairfour == false && w == solution4)
		{
			mismatch++;
			pair44 = true;
		}
				
	}

	if(pairtwo == false)
	{
		if(pair11 == false && pairone == false && x == solution1)
		{
			mismatch++;
			pair11 = true;
		}
		else if(pair33 == false && pairthree == false && x == solution3)
		{
			mismatch++;
			pair33 = true;
		}

		else if(pair44 == false && pairfour == false && x == solution4)
		{
			mismatch++;
			pair44 = true;
		}
				
	}

	if(pairthree == false)
	{
		if(pair11 == false && pairone == false && y == solution1)
		{
			mismatch++;
			pair11 = true;
		}
		else if(pair22 == false && pairtwo == false && y == solution2)
		{
			mismatch++;
			pair22 = true;
		}

		else if(pair44 == false && pairfour == false && y == solution4)
		{
			mismatch++;
			pair44 = true;
		}
				
	}

	if(pairfour == false)
	{
		if(pair22 == false && pairtwo == false && z == solution2)
		{
			mismatch++;
			pair22 = true;
		}
		else if(pair33 == false && pairthree == false && z == solution3)
		{
			mismatch++;
			pair33 = true;
		}

		else if(pair11 == false && pairone == false && z == solution1)
		{
			mismatch++;
			pair11 = true;
		}
				
	}

	printf("With guess %d, you got %d perfect matches and %d misplaced matches.\n", guess_number, perfmatch, mismatch);				//printing out the matches and guess number

	guess_number++;		//increment guess number
	
    return 1;

	
}


