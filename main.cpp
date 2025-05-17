/*! @file main.cpp
	@brief test for the class
	@author Luca Dal Pozzo

	Details.
*/

#include <iostream>
#include "CFunction.h"
#include "CPolynomial.h"
#include "CLogarithmic.h"

// funzione che stampa il risultato di GetValue degli oggetti
void ShowValue(const char *str, double x, double ris){
    cout << "GetValue del " << str << ": se x = " << x << ", f(x) vale: " << ris << endl;
}

int main() {

    //array di puntatori a classe Funzione
    Function *f[6];

    // Coefficienti per il polinomio: 5 + 4x + 3x^2
    double c1[] = {5., 4., 3.};
    int s1 = sizeof(c1) / sizeof(double);

    // Coefficienti per il polinomio: 6 + 3x
    double c2[] = {6., 3.};
    int s2 = sizeof(c2) / sizeof(double);

    // Costruttore con parametri
    Polynomial p1(c1, s1);
    // Costruttore di copia
    Polynomial p2(p1);
    // imposta diversi valori 
    p2.SetPolynomial(c2, s2);
    
    // Costruttore con parametri
    Logarithmic l1(3.,6.);
    // Costruttore di copia
    Logarithmic l2(l1); 
    // imposta diversi valori 
    l2.SetCoefficients(6.,8.);
    
    //associa i puntatori
    f[0] = &p1;
    f[1] = &p2;
    f[2] = &l1;
    f[3] = &l2;

    //esegue il dump degli ogggetti
    for (int i=0; i < 4; i++)
        f[i]->Dump();

    //esegue e mostra GetValue
    cout << endl;
    ShowValue("polinomio 1", 4, f[0]-> GetValue(4));
    ShowValue("polinomio 2", 4, f[1]-> GetValue(4));
    ShowValue("logaritmo 1", 8, f[2]-> GetValue(8));
    ShowValue("logaritmo 2", 8, f[3]-> GetValue(8));

    // Test operator = e ==
    cout << endl << "Test dell'operatore = e ==:" << endl;

    Polynomial p3 = p1;
    f[4]=&p3;
    cout << "Dump di polinomio 3 (assegnato da polinomio 1): ";
    f[4]->Dump();

    Logarithmic l3 = l1;
    f[5]=&l3;
    cout << "Dump di logaritmo 3 (assegnato da logaritmo 1): ";
    f[5]->Dump();

    //confronto p3 con gli altri polinomi
    if (p3 == p1)
        cout << "p3 è uguale a p1 dopo l'assegnazione" << endl;
    else
        cout << "p3 è diverso da p1 dopo l'assegnazione" << endl;
    if (p3 == p2)
        cout << "p3 è uguale a p2 dopo l'assegnazione" << endl;
    else
        cout << "p3 è diverso da p2 dopo l'assegnazione" << endl;

    // confronto l3 con gli altri logarirmi
    if (l3 == l1)
        cout << "l3 è uguale a l1 dopo l'assegnazione" << endl;
    else
        cout << "l3 è diverso da l1 dopo l'assegnazione" << endl;
    if (l3 == l2)
        cout << "l3 è uguale a l2 dopo l'assegnazione" << endl;
    else
        cout << "l3 è diverso da l2 dopo l'assegnazione" << endl;

    return 0;
}