#ifndef REAL_NUMBER_H
#define REAL_NUMBER_H

#include "Number.h"
class RealNumber;  //This is a forward declaration, needed only to remove circular dependencies
#include "PolarNumber.h"
#include "RationalNumber.h"
#include <stdlib.h>

class RealNumber:public Number{
	private:
		//Class variables
		double value;
	public:
		//Empty Constructor		
		RealNumber();
		//Complete Constructor
		RealNumber(double rval);
		//Copy Constructor
		RealNumber(const RealNumber&);

		//Setter and getter functions
		void set_value(double rval);
		double get_value(void) const;

		//Class member functions
		double magnitude();

		//Operation overload for RealNumber (op) RealNumber
		RealNumber operator + (const RealNumber& arg);
		RealNumber operator - (const RealNumber& arg);
		RealNumber operator * (const RealNumber& arg);
		RealNumber operator / (const RealNumber& arg);

		//Operation overload for RealNumber (op) PolarNumber
		PolarNumber operator + (const PolarNumber& arg);
		PolarNumber operator - (const PolarNumber& arg);
		PolarNumber operator * (const PolarNumber& arg);
		PolarNumber operator / (const PolarNumber& arg);

		//Operation overload for RealNumber (op) RationalNumber
		RealNumber operator + (const RationalNumber& arg);
		RealNumber operator - (const RationalNumber& arg);
		RealNumber operator * (const RationalNumber& arg);
		RealNumber operator / (const RationalNumber& arg);

		//Output class variables as string (provided)
		string to_String(void);
};

#endif
