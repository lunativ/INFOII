/*
 * Natural.cpp
 *
 *  Created on: 21 sept. 2020
 *      Author: lunat
 */

#include "Natural.h"


//Implementacion de la clase
//Codigo de los metodos

//Implementacion del constructor por defecto, solo inicializa a 0 el atributo privado
Natural::Natural() {
	n = 0;

}
//Implementacion del constructor ordinario: recibe como argumento el valor a asignar al atributo
Natural::Natural(int v){
	setN(v);
}
////Implementacion del constructor de copia, permite crear un nuevo objeto a partir de los valores de otro objeto del mismo tipo
Natural::Natural(const Natural &v)
{
	//n = v.n;
	setN(v.n);
	//this->n = v.n;
}
//Destructor: en este caso no hace nada
Natural::~Natural() {
	// TODO Auto-generated destructor stub
}

//metodo publico para establecer el valor del atributo privado, controlando que no sea negativo
void Natural::setN(int v)
{
	if(v >= 0)
		n = v;
	else
		n = 0;
}
//metodo publico para acceder al valor del atributo privado
int Natural::getN(void){

	return n;
}

//Metodo para la sobrecarga del operador -
Natural Natural::operator-(Natural a){
	int c = this->n - a.n;
	Natural resultado;
	resultado.setN(c);
	return resultado;
	//o, de manera mas compacta:
	//return Natural(this->n - a.n);
}

//Metodo mostrar
std::string Natural::Mostrar(void)
{
	return "Valor: " + std::to_string(n) + "\n";
}
