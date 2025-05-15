/*! @file CPolynomial.h
	@brief declaration of class Polynomial
	@author Luca Dal Pozzo

	Details.
*/ 

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include "CFunction.h"

class Polynomial : public Function{
	int degree;
    double* coeff;
	
public:
    
    Polynomial();
    Polynomial(const double* coefficients, int size);
    Polynomial(const Polynomial& x);
    ~Polynomial();

    Polynomial& operator =(const Polynomial& x);
    bool operator==(const Polynomial& p);

    void SetPolynomial(const double* coefficients, int size);

    double GetValue(double in);
    void Reset();

    void ErrorMessage(const char *string);
    void WarningMessage(const char *string);
    void Dump();
    
};

#endif