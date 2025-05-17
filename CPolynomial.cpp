/*! @file CPolynomial.cpp
	@brief Definition of class Polynomial
	@author Luca Dal Pozzo

	Details.
*/

#include "CPolynomial.h"

/// @brief default constructor
Polynomial::Polynomial() {
    degree = -1;
    coeff = NULL;
}

/// @brief parameter constructor
/// @param coefficients coefficenti del polinomio
/// @param size dimensione del polinomio
Polynomial::Polynomial(const double* coefficients, int size) {
    SetPolynomial(coefficients, size);
}

/// @brief destructor
Polynomial::~Polynomial() {
    if (coeff != NULL) {
        delete[] coeff;
        coeff = NULL;
    }
}


/// @brief copy constructor
/// @param p oggetto della classe polinomio da copiare 
Polynomial::Polynomial(const Polynomial& p) {
    if (p.coeff == NULL) {
        ErrorMessage("Copy constructor: the object to be copied has no coefficients");
        exit(-1);
    }
    SetPolynomial(p.coeff, (p.degree +1));
}

/// @brief operator=
/// @param p oggetto della classe polinomio  
Polynomial& Polynomial::operator=(const Polynomial& p) {
    if (this != &p) {
        if (coeff != NULL)
            delete[] coeff;

        SetPolynomial(p.coeff, (p.degree +1));
    }
    return *this;
}

/// @brief operator==
/// @param p oggetto della classe polinomio  
bool Polynomial::operator==(const Polynomial& p) {
    if (degree != p.degree)
        return false;

    for (int i = 0; i <= degree; ++i) {
        if (coeff[i] != p.coeff[i])
            return false;
    }
    return true;
}

/// @brief funzione che inserisce i valori del polinomio
/// @param coefficients coefficenti del polinomio
/// @param size dimensione del polinomio  
void Polynomial::SetPolynomial(const double* coefficients, int size) {
    if (size < 1) {
        ErrorMessage("SetPolynomial: the degree of the Polynomial cannot be negative");
        return;
    }

    if (coeff != NULL)
        Reset();

    degree = size - 1;
    coeff = new double[size];
    for (int i = 0; i <= degree; ++i)
        coeff[i] = coefficients[i];
}

/// @brief funzione che prende come parametro un valore x e calcola f(x) 
/// @param in parametro da sostituire a x
double Polynomial::GetValue(double in)  {
    double x = in;
    double result = coeff[0];

    for (int i = 1; i <= degree; ++i) {
        result += coeff[i] * x;
        x *= in; // x^i
    }

    return result;
}

/// @brief funzione che azzera il polinomio, porta a zero i valori 
void Polynomial::Reset() {
    degree = -1;
    if (coeff != NULL) {
        delete[] coeff;
        coeff = NULL;
    }
}

/// @brief funzione che mostra il polinomio
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

