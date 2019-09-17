//============================================================================
// Name        : Clase_timer.cpp
// Author      : vl
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <math.h>
using namespace std;


class Contador
{
	long int cuenta;		//variable para mantener el valor de cuenta controlado por los metodos inc, Reset y setCuenta
	clock_t cuenta_t;		//variable que se utiliza para almacenar un tiempo inicial de cuenta en ciclos de reloj, usado por los metodos tic y toc


public:
	Contador(void);		//constructor sin parametros
	Contador(int c);	//constructor con valor inicial de cuenta
	void inc(void);		//metodo que incrementa en 1 el valor de  cuenta
	void Reset(void);	//metodo que resetea (pone en 0) el valor de cuenta
	void setCuenta(int c);	//metodo set de la variable cuenta
	int getCuenta(void);	//metodo get de la variable cuenta
	bool operator <(const Contador & c1);	//metodo para sobrecarga del operador binario menor (<)
	void tic(void);		//metodo tic, para iniciar medicion de tiempo
	float toc(void);	//metodo toc, devuelve el tiempo en segundos que transcurrio desde la ultima llamada a tic()
};

Contador::Contador(void)
{
	cuenta = 0;
	cuenta_t = clock();


}
Contador::Contador(int c)
{
	cuenta = 0;
	cuenta_t = clock();

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

	Contador cclock;
	cclock.tic();


	for(int i = 0; i< 100000; i++)
	{}
	cout<< "tiempo "<<cclock.toc();
	return 0;
}

void Contador::tic(void)
{
	cuenta_t = clock();
}
float Contador::toc(void)
{
	clock_t cuenta_toc = clock();
	clock_t total_t = (double)(cuenta_toc - cuenta_t);
	return  (float) total_t / CLOCKS_PER_SEC ;
}
