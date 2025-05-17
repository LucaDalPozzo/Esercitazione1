/*! @file CFunction.h
	@brief A virtual base class for functions of a single variable
	@author Luca Dal Pozzo

	La classe Function è una classe base astratta per rappresentare funzioni matematiche generiche.
 	Ogni funzione derivata deve implementare il metodo GetValue() per calcolare il valore della funzione
 	per un dato input. Inoltre, le funzioni devono implementare Dump() per stampare una rappresentazione della funzione.
*/ 

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

///@class Function
///@brief Classe astratta per rappresentare funzioni matematiche generiche. 
class Function {
		
public:
    
	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
    Function();
    virtual ~Function();
	/// @}

	/// @name GETTERS
	/// @{
	virtual double GetValue(double in)=0;
	/// @}

	/// @name DEBUG 
	/// @{
	virtual void Dump()=0;
	/// @}

	/// @name ERROR MESSAGE 
	/// @{
	void ErrorMessage(const char* string);
	/// @}
};

#endif