#include "ComplexNumber.h"

//to_String converts mag and phase components to string of type a<b
string ComplexNumber::to_String(void){

        stringstream my_output;
	my_output << magComponent<< "<"<<180.0*phaseComponent/M_PI;
        return my_output.str();

}
