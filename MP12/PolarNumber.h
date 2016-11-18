#ifndef POLAR_NUMBER_H
#define POLAR_NUMBER_H

#include "Number.h"
class PolarNumber;  //This is a forward declaration, needed only to remove circular dependencies
#include "RealNumber.h"
#include "RationalNumber.h"
#include <cmath>
#include <iostream>

class PolarNumber:public Number{
	private:
		//Class variables
		double magComponent;
		double phaseComponent;
	public:
		//Empty Constructor
		PolarNumber();
		//Complete Constructor
		PolarNumber(double magnitude, double phase);
		PolarNumber( const PolarNumber& other );

		//Setter and getter functions
		void set_magComponent(double mval);
		void set_phaseComponent(double phval);
		double get_magComponent(void) const;
		double get_phaseComponent(void) const;
		void set_value (double mval, double phval);


		//Operation overload for PolarNumber (op) PolarNumber
		PolarNumber operator + (const PolarNumber& arg);
		PolarNumber operator - (const PolarNumber& arg);
		PolarNumber operator * (const PolarNumber& arg);
		PolarNumber operator / (const PolarNumber& arg);

		//Operation overload for PolarNumber (op) RealNumber		
		PolarNumber operator + (const RealNumber& arg);
		PolarNumber operator - (const RealNumber& arg);
		PolarNumber operator * (const RealNumber& arg);
		PolarNumber operator / (const RealNumber& arg);

		//Operation overload for PolarNumber (op) RationalNumber	
		PolarNumber operator + (const RationalNumber& arg);
		PolarNumber operator - (const RationalNumber& arg);
		PolarNumber operator * (const RationalNumber& arg);
		PolarNumber operator / (const RationalNumber& arg);

		//Output class variables as string (provided)
		string to_String(void);
};

#endif
