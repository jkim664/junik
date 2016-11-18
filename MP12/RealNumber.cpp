#include "RealNumber.h"

//to_String converts real and imaginary components to string of type a+bi
string RealNumber::to_String(void){
	stringstream my_output;
	my_output << value;
	return my_output.str();
}

