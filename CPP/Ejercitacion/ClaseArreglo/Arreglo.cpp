/*
 * Arreglo.cpp
 *
 *  Created on: 23 sept. 2021
 *      Author: lunat
 */

#include "Arreglo.h"
#include <iostream>

using namespace std;
namespace Ejercicios {

Arreglo::Arreglo(int t) {

	if(t < 1){
		tam = 10;//si se recibe un tamaño no valido se usa el valor por defecto
	}
	else
	{
		tam = t;
	}
	ptr = new int[tam];// (int *) malloc(10*sizeof(int))
	for(int i = 0; i<tam; i++)
		ptr[i]=0;
	nro_instancias++;
}

Arreglo::~Arreglo() {
	delete [] ptr;
	nro_instancias--;
}


Arreglo& Arreglo::operator=(const Arreglo &o){


	//delete [] ptr;
	this->tam = o.tam;
	ptr = new int[tam];
	for(int i=0; i < tam; i++)
	{
		ptr[i]= o.ptr[i];
	}

	return *this;
}

void Arreglo::Mostrar() {
	cout<<endl<<"Arreglo N = "<<tam<<"("<<ptr<<"): "<<endl;
	for(int i = 0; i<tam; i++)
	{

		cout<<ptr[i]<<", ";

	}
	cout<<endl;
}

void Arreglo::CargarValores(void) {
	cout<<endl<<"Ingrese valores:"<<endl;
	for(int i = 0; i<tam; i++)
	{
		cout<<"Elemento "<<i<<": ";
		cin>>ptr[i];
		cout<<endl;
	}
}

void Arreglo::SetElementoN(int n, int v) {
	if((n>=0) && (n<tam))
		ptr[n] = v;
}

int Arreglo::GetElementoN(int n) {
	if((n>=0) && (n<tam))
		return ptr[n];
	else
		return 0;
}

int Arreglo::getNroInstancias(void){
	return nro_instancias;
}
} /* namespace Ejercicios */
