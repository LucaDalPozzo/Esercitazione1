/*! @file CPolynomial.cpp
	@brief Definition of class Polynomial
	@author Luca Dal Pozzo

	Details.
*/

#include "CPolynomial.h"

Polynomial::Polynomial() {
    degree = -1;
    coeff = NULL;
}

Polynomial::Polynomial(const double* coefficients, int size) {
    coeff = NULL;
    SetPolynomial(coefficients, size);
}

Polynomial::~Polynomial() {
    if (coeff != NULL) {
        delete[] coeff;
        coeff = NULL;
    }
}

Polynomial::Polynomial(const Polynomial& p) {
    if (p.coeff == NULL) {
        ErrorMessage("Copy constructor: the object to be copied has no coefficients");
        exit(-1);
    }

    degree = p.degree;
    coeff = new double[degree + 1];
    for (int i = 0; i <= degree; ++i)
        coeff[i] = p.coeff[i];
}

Polynomial& Polynomial::operator=(const Polynomial& p) {
    if (this != &p) {
        if (coeff != NULL)
            delete[] coeff;

        degree = p.degree;
        coeff = new double[degree + 1];
        for (int i = 0; i <= degree; ++i)
            coeff[i] = p.coeff[i];
    }
    return *this;
}

bool Polynomial::operator==(const Polynomial& p) {
    if (degree != p.degree)
        return false;

    for (int i = 0; i <= degree; ++i) {
        if (coeff[i] != p.coeff[i])
            return false;
    }
    return true;
}

void Polynomial::SetPolynomial(const double* coefficients, int size) {
    if (size < 1) {
        ErrorMessage("SetPolynomial: the degree of the Polynomial cannot be negative");
        exit(-1);
    }

    if (coeff != NULL)
        Reset();

    degree = size - 1;
    coeff = new double[size];
    for (int i = 0; i <= degree; ++i)
        coeff[i] = coefficients[i];
}

double Polynomial::GetValue(double in)  {
    double x = in;
    double result = coeff[0];

    for (int i = 1; i <= degree; ++i) {
        result += coeff[i] * x;
        x *= in; // x^i
    }

    return result;
}

void Polynomial::Reset() {
    degree = -1;
    if (coeff != NULL) {
        delete[] coeff;
        coeff = NULL;
    }
}

void Polynomial::ErrorMessage(const char* string)  {
    cout << endl << "ERROR -- Polynomial -- " << string << endl;
}

void Polynomial::WarningMessage(const char* string)  {
    cout << endl << "WARNING -- Polynomial -- " << string << endl;
}

void Polynomial::Dump()  {
    if (degree == -1) {
        cout << "Uninitialized polynomial" << endl;
        return;
    }

    if (coeff == NULL) {
        cout << "Degree: " << degree << endl;
        cout << "No coefficients available" << endl;
        return;
    }

    for (int i = 0; i <= degree; ++i) {
        if (coeff[i] != 0.0) {
            cout << (coeff[i] > 0 && i > 0 ? " + " : " ") << coeff[i];
            if (i > 0) {
                cout << "x";
                if (i > 1)
                    cout << "^" << i;
            }
        }
    }
    cout << endl;
}

