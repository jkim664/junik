#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159
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
	//Intro - this code implements the differential equation in C. It takes 
	//values Voutnew, Voutcur and Voutprev and manipulates those values to figuree
	//out the 2nd order low pass filter using the finite difference method.
	for(i = 0; i < N; i++)
	{

	Voutprev = Voutcur;	//put value of current to previous one 
	Voutcur = Voutnew;	//put value of new to current one 
	printf("%lf\n", Voutnew);
			
	double comp1 = 1/(sqrt(2)*dt*omegac); 
	double comp2 = 1/(pow(dt*omegac,2));
	double comp3 = 1/(comp1 + comp2);
	double comp4 = ((2/(pow(dt*omegac,2))) - 1)*Voutcur;
	double comp5 = (comp1 - comp2)*Voutprev;
	double comp6 = sin(omega1*i*dt) + .5*sin(omega2*i*dt);

	Voutnew = comp3*(comp4 + comp5 + comp6); 

	}
	return 0;
}
