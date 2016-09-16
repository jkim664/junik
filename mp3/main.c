#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double omega1, omega2, omegac, T, dt;
	int N;

	//Scan the inputs from the user.
	scanf("%lf %lf %lf", &omega1, &omega2, &omegac);
	
	T = 3 * 2 * M_PI / omega1;      // Total time
    	N = 20 * T / (2 * M_PI / omega2);   // Total number of time steps
    	dt = T / N;             // Time step

	int i;
	double Voutnew = 0, Voutcur = 0, Voutprev = 0;

	//Write your code here!


	return 0;
}
