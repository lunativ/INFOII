/*
 * Complex.cpp
 *
 *  Created on: 29 oct. 2018
 *      Author: vlunati
 *      fuente: https://codereview.stackexchange.com/questions/79192/basic-complex-number-class
 */

#include "Complex.h"
#include "assert.h"

namespace Ejercicios {

// ---------- global funcs ----------
// Sobrecarga de operadores para la clase Complex mediante funciones globales,
// observar que utilizan los metodos set y get de la clase ya que una funcion global no amiga
// no puede tener acceso a propiedades privadas de la clase Complex

bool operator==(const Complex a_, const Complex b_)
{
    return (a_.GetR() == b_.GetR() && a_.GetI() == b_.GetI());
}

bool operator!=(const Complex a_, const Complex b_)
{
	return !(a_ == b_);
}

Complex operator+(const Complex a_, const Complex b_)
{
    Complex ret(a_.GetR()+b_.GetR(), a_.GetI()+b_.GetI());
    return ret;
    //otra manera:
    //return a_ += b_;
}

Complex operator-(const Complex a_, const Complex b_)
{
    Complex ret(a_.GetR()-b_.GetR(), a_.GetI()-b_.GetI());
    return ret;
}

Complex operator*(const Complex a_, const Complex b_)
{
    double a=a_.GetR(), b=a_.GetI();
    double c=b_.GetR(), d=b_.GetI();

    Complex ret(a*c-b*d, b*c+a*d);

    return ret;
}

Complex operator/(const Complex a_, const Complex b_)
{
    double a=a_.GetR(), b=a_.GetI();
    double c=b_.GetR(), d=b_.GetI();
    assert(c || d);		//muestra error en consola si c y d son igual a cero

    Complex ret((a*c+b*d)/(c*c+d*d), (b*c-a*d)/(c*c+d*d));

    return ret;
}

//Sobrecarga de los operadores de insercion y extraccion de flujo,
//permiten utilizar objetos de la clase Complex directamente con cout y cin

std::ostream& operator<<(std::ostream& os_, const Complex& comp_)
{
    return os_ << '(' << comp_.GetR() << ',' << comp_.GetI() << "i)";
}

std::istream& operator>>(std::istream& is_, Complex& comp_) // assumes (a,bi) format
{
    char ch = 0;
    double r = 0;
    double i = 0;

    is_ >> ch >> r >> ch >> i >> ch >> ch;

    comp_.SetR(r);
    comp_.SetI(i);

    return is_;
}

// ---------- interface funcs ----------
// Implementacion de metodos de la clase Complex
Complex::Complex(const double r_, const double i_): m_r(r_), m_i(i_)	//esta es una manera de implementar un constructor encadenando el constructor de la clase complex con constructor de clases double en este caso
{}

/* otra implementacion seria:
 Complex::Complex(const double r_, const double i_)
 {
 	 m_r = r_;
 	 m_i = i_;
 }
 */


// a continuacion se implementan los operadores aritmeticos += -= *= y /= como metodos de la clase
// los otros operadores se implementan mediante funciones globales


Complex& Complex::operator+=(const Complex o_)
{
    m_r += o_.m_r;
    m_i += o_.m_i;

    return *this;
}

Complex& Complex::operator-=(const Complex o_)
{
    m_r -= o_.m_r;
    m_i -= o_.m_i;

    return *this;
}

Complex& Complex::operator*=(const Complex o_)
{
    double a=m_r, b=m_i, c=o_.m_r, d=o_.m_i;
    m_r = a*c - b*d;
    m_i = b*c + a*d;

    return *this;
}

Complex& Complex::operator/=(const Complex o_)
{
    assert(o_.m_r || o_.m_i);
    double a=m_r, b=o_.m_r, c=m_i, d=o_.m_i;
    m_r = (a*c+b*d)/(c*c+d*d);
    m_i = (b*c-a*d)/(c*c+d*d);

    return *this;
}

double Complex::GetR()const
{
    return m_r;
}

double Complex::GetI()const
{
    return m_i;
}

void Complex::SetR(const double r_)
{
    m_r = r_;
}

void Complex::SetI(const double i_)
{
    m_i = i_;
}

} /* namespace Ejercicios */
