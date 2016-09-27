#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//this program uses halley's method to calculate and find roots of a fucntion. 
//to do this, this program first finds if the bounds have roots. Then, it iterates
//x values inside the given domain to find all the roots.


double abs_double(double y)
{

    return fabs(y);
}

double fx_val(double a, double b, double c, double d, double e, double x)
{
	double pow4, pow3, pow2, pow1, result;
	
	pow4 = a*x*x*x*x;
	pow3 = b*x*x*x;
	pow2 = c*x*x;
	pow1 = d*x;

	result = pow4+pow3+pow2+pow1+e;	

    return result;
}

double fx_dval(double a, double b, double c, double d, double e, double x)
{
	double dpow4, dpow3, dpow2, dresult;

	dpow4 = 4*a*x*x*x;
	dpow3 = 3*b*x*x;
	dpow2 = 2*c*x;

	dresult = dpow4+dpow3+dpow2+d;	
    return dresult;
}

double fx_ddval(double a, double b, double c, double d, double e, double x)
{
	double ddpow4, ddpow3, ddpow2, ddresult;

	ddpow4 = 4*3*a*x*x;
	ddpow3 = 3*2*b*x;
	ddpow2 = 2*1*c;

	ddresult = ddpow4+ddpow3+ddpow2;
    return ddresult;
}


double newrfind_halley(double a, double b, double c, double d, double e, double x)
{
	double xn, xnnew, numer, denom, denom1, denom2, negcomp;

	xn = x;
	numer = 2 * fx_val(a,b,c,d,e,x) * fx_dval(a,b,c,d,e,x);
	denom1 = 2 * abs_double(fx_dval(a,b,c,d,e,x)) * abs_double(fx_dval(a,b,c,d,e,x));
	denom2 = fx_val(a,b,c,d,e,x) * fx_ddval(a,b,c,d,e,x);
	denom = denom1 - denom2;
	negcomp = numer/denom;

	xnnew = xn - negcomp;

    return xnnew;
}

int rootbound(double a, double b, double c, double d, double e, double r, double l)
{
	int vr = 0;
	int vl = 0;
	int lcomp1, lcomp2, lcomp3, lcomp4, rcomp1, rcomp2, rcomp3, rcomp4;

	lcomp1 = 4*a*l + b;
	lcomp2 = 6*a*l*l + 3*b*l + c;
	lcomp3 = 4*a*l*l*l + 3*b*l*l + 2*c*l + d;
	lcomp4 = 4*a*l*l*l*l + b*l*l*l + c*l*l + d*l + e;

	rcomp1 = 4*a*r + b;
	rcomp2 = 6*a*r*r + 3*b*r + c;
	rcomp3 = 4*a*r*r*r + 3*b*r*r + 2*c*r + d;
	rcomp4 = 4*a*r*r*r*r + b*r*r*r + c*r*r + d*r + e;
//compute vl
	if((a>0 && lcomp1<0) || (a<0 && lcomp1>0))
		vl++;
	else
		vl = vl;
	if((lcomp1>0 && lcomp2<0) || (lcomp1<0 && lcomp2>0))
		vl++;
	else
		vl = vl;
	if((lcomp2>0 && lcomp3<0) || (lcomp2<0 && lcomp3>0))
		vl++;
	else
		vl = vl;
	if((lcomp3>0 && lcomp4<0) || (lcomp3<0 && lcomp4>0))
		vl++;
	else
		vl = vl;
//compute vr
	if((a>0 && rcomp1<0) || (a<0 && rcomp1>0))
		vr++;
	else
		vr = vr;
	if((rcomp1>0 && rcomp2<0) || (rcomp1<0 && rcomp2>0))
		vr++;
	else
		vr = vr;
	if((rcomp2>0 && rcomp3<0) || (rcomp2<0 && rcomp3>0))
		vr++;
	else
		vr = vr;
	if((rcomp3>0 && rcomp4<0) || (rcomp3<0 && rcomp4>0))
		vr++;
	else
		vr = vr;

    return abs_double(vl - vr);
}

int main(int argc, char **argv)
{
	double a, b, c, d, e, l, r;
	FILE *in;

	if (argv[1] == NULL) {
		printf("You need an input file.\n");
		return -1;
	}
	in = fopen(argv[1], "r");
	if (in == NULL)
		return -1;
	fscanf(in, "%lf", &a);
	fscanf(in, "%lf", &b);
	fscanf(in, "%lf", &c);
	fscanf(in, "%lf", &d);
	fscanf(in, "%lf", &e);
	fscanf(in, "%lf", &l);
	fscanf(in, "%lf", &r);
    
    //The values are read into the variable a, b, c, d, e, l and r.
    //You have to find the bound on the number of roots using rootbound function.
    //If it is > 0 try to find the roots using newrfind function.
    //You may use the fval, fdval and fddval funtions accordingly in implementing the halleys's method.
	
	if (rootbound(a, b, c, d, e, r, l) == 0){
		printf("The polynomial has no roots in the given interval.\n");
		return 0;
	}
	
	double xcurrent, xnew, diff;
	int j;
	int rootcount = 0;
	double i;
	xnew = 0;
	
	for(i = l; i <= r; i = i + 0.5)
	{		
		xnew = i;
		for(j = 0; j < 10000; j++)
		{	
			xcurrent = xnew;		
			
			xnew = newrfind_halley(a, b, c, d, e, xcurrent);

			diff = xnew - xcurrent;

				if(abs_double(diff) <= 0.000001)
					{		
						printf("Root is found!: %lf\n", xnew);

						rootcount++;

						j = 10000;
					}
		}
	}

	if(rootcount == 0)
		printf("No roots found.\n");    
    
    fclose(in);
    
    return 0;
}
