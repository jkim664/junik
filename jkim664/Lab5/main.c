/* Code to simulate rolling three six-sided dice (D6)
 * User first types in seed value
 * Use seed value as argument to srand()
 * Call roll_three to generate three integers, 1-6
 * Print result "%d %d %d "
 * If triple, print "Triple!\n"
 * If it is not a triple but it is a dobule, print "Double!\n"
 * Otherwise print "\n"
 */

#include <stdio.h>
#include <stdlib.h>
#include "dice.h"

int main()
{
	int one, two, three, seed;
	printf("enter a seed number.\n");
	scanf("%d", &seed);
	srand(seed); 
	roll_three(&one, &two, &three);
	printf("%d %d %d\n", one, two, three);
	
	if(one == two && two == three)
	printf("triple!\n");
	else if(one == two)
	printf("double!\n");
	else if(one == three)
	printf("double!\n");
	else if(two == three)
	printf("double!\n");

return 0;
}
