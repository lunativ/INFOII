//============================================================================
// Name        : Clase_timer.cpp
// Author      : vl
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <stdio.h>
#include <math.h>
using namespace std;


class Contador
{
	int cuenta;

public:
	Contador(void);
	Contador(int c);
	void inc(void);
	void Reset(void);
	void setCuenta(int c);
	int getCuenta(void);
	bool operator <(const Contador & c1);
};

Contador::Contador(void)
{
	cuenta = 0;
}
Contador::Contador(int c)
{
	cuenta = c;
}
void Contador::inc(void)
{
	cuenta++;
}
void Contador::Reset(void)
{
	cuenta = 0;
}
void Contador::setCuenta(int c)
{
	cuenta = c;
}
int Contador::getCuenta(void)
{
	return cuenta;
}
bool Contador::operator <(const Contador & c1)
{
	int x = this->cuenta;
	int y = c1.cuenta;
	return x < y;
}


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Contador c1;
	Contador c2(10);
	cout << c1.getCuenta() << ", " << c2.getCuenta() << endl;
	c1.inc();
	c2.inc();
	cout << c1.getCuenta() << ", " << c2.getCuenta() << endl;
	if(c1 < c2)
		cout << "c1 < c2";
	else
		cout << "c1 > c2";
	return 0;
}
