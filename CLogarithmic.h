/*! @file CLogarithmic.h
	@brief declaration of class Logarithmic
	@author Luca Dal Pozzo

	Details.
*/ 

#ifndef CLOGARITHMIC_H
#define CLOGARITHMIC_H

#include "CFunction.h"  

///@class Logarithmic
///@brief Classe per rappresentare logaritmi
class Logarithmic : public Function {
private:
    double b_coeff;  // base del logaritmo
    double k_coeff;  // coefficiente moltiplicativo

public:
    /// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
    Logarithmic();
    Logarithmic(double k, double b);
    Logarithmic(const Logarithmic& l);
    ~Logarithmic();
    /// @}

    /// @name OPERATORS
	/// @{
    Logarithmic& operator =(const Logarithmic& x);
    bool operator==(const Logarithmic& p);
    /// @}

    /// @name GETVALUE AND DUMP
	/// @{
    double GetValue(double in);
    void Dump();
    /// @}

    /// @name BASIC HANDLING
	/// @{
    void SetCoefficients(double k, double b);
    /// @}
};

#endif
