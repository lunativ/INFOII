/*
 * Natural.h
 *
 *  Created on: 21 sept. 2020
 *      Author: lunat
 */

#ifndef NATURAL_H_
#define NATURAL_H_
#include <string>
using namespace std;

class Natural {
private:	//todo lo declarado luego de private solo podra ser accedido por metodos de la clase
	int n;//variable de la clase -> propiedad o atributo de la clase
public:		//todo lo declarado luego de public podrá ser accedido por funciones externas a la clase como main
	//funciones o metodos:
	//Constructores
	Natural();//constructor por defecto (sin argumentos)
	Natural(int v);//constructor ordinario (con argumentos)
	Natural(const Natural & v);//constructor de copia (permite crear un objeto a partir de otro)
	//Destructor: se ejecuta al eliminarse un objeto o terminar el programa
	~Natural();// usualmente libera memoria, cierra archivos o puertos: free, close fclose delete

	//Metodos de funcion general
	Natural Suma(Natural a, Natural b){ return Natural(a.n+b.n);}//implementacion inline
	std::string Mostrar(void);
	//Metodos para sobrecarga de operadores
	Natural operator+(Natural a){ return Natural(this->n + a.n);}
	Natural operator-(Natural a);

	//metodos de acceso a los atributos
	void setN(int a);
	int getN(void);

};

#endif /* NATURAL_H_ */
