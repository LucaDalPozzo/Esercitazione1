/*! @file CLogarithmic.h
	@brief declaration of class Logarithmic
	@author Luca Dal Pozzo

	Details.
*/ 

#ifndef LOGARITHMIC_H
#define LOGARITHMIC_H

#include "CPolynomial.h"

class Logarithmic : public Polynomial{
	double k_coeff;
    double b_coeff;
	
public:
    
    Logarithmic();
    Logarithmic(double k_coeff, double b_coeff);
    Logarithmic(const Logarithmic& x);
    ~Logarithmic();

    double GetValue(double in);
    void Dump();
    
};

#endif