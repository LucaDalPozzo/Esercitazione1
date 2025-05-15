#include <iostream>
#include "CPolynomial.h"

int main() {
    // Coefficienti per il polinomio: 1 + 2x + 3x^2
    double coeffs[] = {1.0, 2.0, 3.0};
    int size = sizeof(coeffs) / sizeof(double);

    // Costruttore con parametri
    Polynomial p1(coeffs, size);

    // Dump del polinomio
    std::cout << "Polinomio p1: ";
    p1.Dump();

    // Valore del polinomio in x = 2
    double x = 2.0;
    std::cout << "Valore di p1 in x = " << x << " : " << p1.GetValue(x) << std::endl;

    // Copy constructor
    Polynomial p2(p1);
    std::cout << "Polinomio p2 (copia di p1): ";
    p2.Dump();

    // Operatore ==
    if (p1 == p2)
        std::cout << "p1 e p2 sono uguali." << std::endl;
    else
        std::cout << "p1 e p2 sono diversi." << std::endl;

    // Modifica p2
    double newCoeffs[] = {0.0, 0.0, 1.0};
    p2.SetPolynomial(newCoeffs, 3);
    std::cout << "p2 dopo la modifica: ";
    p2.Dump();

    // Operatore di assegnazione
    Polynomial p3;
    p3 = p2;
    std::cout << "Polinomio p3 (assegnato da p2): ";
    p3.Dump();

    return 0;
}
