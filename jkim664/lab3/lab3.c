#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159
double	omega1, omega2; 
int	i, n; 
	
int main() 
{
	printf("input n, omega1, and omega2 \n");
	scanf("%d %lf %lf", &n, &omega1, &omega2);

	for( i = 0; i < n; i++)
	{
		double x = i * PI / n;
		double f = sin(omega1 * x) + sin(omega2 * x) / 2;
		printf("(%lf, %lf) \n", x, f);
	}
return 0;
}	 	
