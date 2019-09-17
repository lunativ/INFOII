/*
 * Complex.h
 *
 *  Created on: 29 oct. 2018
 *      Author: vlunati
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>
using namespace std;

namespace Ejercicios {

class Complex;

//Sobrecarga mediante funcion global operadores << y >> para  mostrar numeros complejos en consola
std::ostream& operator<<(std::ostream&, const Complex&);
std::istream& operator>>(std::istream&, Complex&); // assumes (a,bi) format

//sobrecarga de operadores aritmeticos mediante funciones globales
bool operator==(const Complex, const Complex);
bool operator!=(const Complex, const Complex);

Complex operator+(const Complex, const Complex);
Complex operator-(const Complex, const Complex);
Complex operator*(const Complex, const Complex);
Complex operator/(const Complex, const Complex);

//Definicion de clase Complex

class Complex
{
public:
    Complex(const double r_=0, const double i_=0);// non explicit on purpse



    Complex& operator+=(const Complex);
    Complex& operator-=(const Complex);
    Complex& operator*=(const Complex);
    Complex& operator/=(const Complex);

    double GetR()const;
    double GetI()const;

    void SetR(const double);
    void SetI(const double);

private:
    double m_r;
    double m_i;
};

} /* namespace Ejercicios */

#endif /* COMPLEX_H_ */
