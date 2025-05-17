/*! @file CPolynomial.h
	@brief declaration of class Polynomial
	@author Luca Dal Pozzo

	Details.
*/ 

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "CFunction.h"


///@class Polynomial
///@brief Classe per rappresentare polinomi
class Polynomial : public Function{
	int degree;
    double* coeff;
	
public:
    
    /// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
    Polynomial();
    Polynomial(const double* coefficients, int size);
    Polynomial(const Polynomial& x);
    ~Polynomial();
    /// @}

    /// @name OPERATORS
	/// @{
    Polynomial& operator =(const Polynomial& x);
    bool operator==(const Polynomial& p);
    /// @}

    /// @name GETVALUE AND DUMP
	/// @{
    double GetValue(double in);
    void Dump();
    /// @}
    
    /// @name BASIC HANDLING
	/// @{
    void SetPolynomial(const double* coefficients, int size);
    void Reset();
    /// @}
};

#endif