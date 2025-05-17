/*! @file CFunction.cpp
	@brief Definition of class Function
	@author Luca Dal Pozzo

	Details.
*/

#include "CFunction.h"

/// @brief constructor 
Function::Function(){};

/// @brief destructor
Function::~Function(){};

/// @brief Error message 
/// @param string messaggio di errrore
void Function::ErrorMessage(const char* string)  {
    cout << endl << "ERROR " << string << endl;
}