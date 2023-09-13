//============================================================================
// Name        : Clase_arreglo.cpp
// Author      : VL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Arreglo.h"
using namespace std;
using namespace Ejercicios;
int Arreglo::nro_instancias = 0;//inicializo atributo estatico de la clase Arreglo

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Arreglo a1(4);
	a1.CargarValores();
	Arreglo a2(10);
	Arreglo a3(8);
	a2.SetElementoN(0,2);
	a2.SetElementoN(1,5);

	a1.Mostrar();
	a2.Mostrar();
	a1 = a2;
	a1.Mostrar();
	//puedo llamar a un metodo estatico a travez del nombre de la clase
	//en este caso utilizo un metodo estatico para acceder a un atributo estatico privado
	cout<<"Numero de arreglos: "<< Arreglo::getNroInstancias();
	return 0;
}
