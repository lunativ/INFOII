//============================================================================
// Name        : Clase_contador.cpp
// Author      : VL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <ctime>
#include <iostream>
#include <cstdlib>


#include "Contador.h"
using namespace std;


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	std::srand( ( unsigned int )std::time( nullptr ) );
	int random_number =0;

	Contador pares, impares;
	pares.reset();//pone a cero el contador
	impares.reset();//pone a cero el contador
	for(int i = 0; i<10000; i++)
	{
		random_number = (std::rand() % 100); // rand() return a number between 0 and RAND_MAX
		cout<<"i: "<<random_number<<endl;
		if(random_number % 2 == 0)
			pares.incrementar();
		else
			impares.incrementar();
	}
	cout<< "Cantidad de numeros pares: "<< pares <<endl<<"Cantidad de impares: "<<impares;


	return 0;
}
