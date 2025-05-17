/*! @file CLogarithmic.cpp
	@brief Definition of class Logarthmic
	@author Luca Dal Pozzo

	Details.
*/

#include "CLogarithmic.h"
#include <iostream>
#include <cmath>

using namespace std;

/// @brief default constructor
Logarithmic::Logarithmic() {
    SetCoefficients(1., 10.);
}

/// @brief parameter constructor
/// @param k coefficiente moltiplicativo
/// @param b base del logaritmo
Logarithmic::Logarithmic(double k, double b) {
    SetCoefficients(k, b);
}

/// @brief copy constructor
/// @param l oggetto della classe logaritmo da copiare 
Logarithmic::Logarithmic(const Logarithmic& l){
    SetCoefficients(l.k_coeff, l.b_coeff);
}

/// @brief destructor
Logarithmic::~Logarithmic() {}


/// @brief operator=
/// @param x oggetto della classe logaritmo  
Logarithmic& Logarithmic::operator=(const Logarithmic& x){
    SetCoefficients(x.k_coeff, x.b_coeff);
    return *this;
}

/// @brief operator==
/// @param x oggetto della classe polinomio
bool Logarithmic::operator==(const Logarithmic& x){
    if (x.b_coeff != b_coeff || x.k_coeff != k_coeff)
        return false;
    return true;
}

/// @brief funzione che prende come parametro un valore x e calcola f(x) 
/// @param in parametro da sostituire a x
double Logarithmic::GetValue(double in) {
    if (in <= 0.0) {
        ErrorMessage("GetValue: il logaritmo non è definito per x ≤ 0.");
        exit(-1);
    }

    return k_coeff * (log(in) / log(b_coeff)); // log_b(x) = ln(in) / ln(b)
}

/// @brief funzione che mostra il logaritmo
void Logarithmic::Dump() {
    cout << "f(x) = " << k_coeff << " * log_" << b_coeff << "(x)" << endl;
}

/// @brief funzione che inserisce i valori del logaritmo
/// @param k coefficiente moltiplicativo
/// @param b base del logaritmo
void Logarithmic::SetCoefficients(double k, double b) {
    if (b <= 0.0 || b == 1.0) {
        ErrorMessage("SetCoefficients: la base del logaritmo deve essere > 0 e ≠ 1.");
        return;
    }
    k_coeff = k;
    b_coeff = b;
}