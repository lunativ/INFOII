//============================================================================
// Name        : Clases_herencia_.cpp
// Author      : VL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Coordenada
{
	int x,y;
public:
	Coordenada();
	void setX(int d){y = d;}
	void setY(int d){x = d;}
	int getX(void){return x;}
	int getY(){return y;}
	void mostrar(void){cout<<"Coordenadas: "<<x<<", "<<y<<";";}
};
Coordenada::Coordenada(){
	srand(20);	//semilla para generar numeros aleatorios de forma repetible
	x = rand();
	y = rand();
}

class Complejo: public Coordenada{
public:
	Complejo():Coordenada(){}
	Complejo(int r, int i);
	void mostrar(){cout<<"Complejo: "<< this->getX() <<"+ j "<< this->getY() <<";";}
};
Complejo::Complejo(int r, int i){
	this->setX(r);
	this->setY(i);
}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Coordenada c1;
	c1.mostrar();
	cout << endl;
	Complejo z1, z2(2,3);
	z1.mostrar();
	cout << endl;
	z2.mostrar();
	cout << endl;

	z1.Coordenada::mostrar();
	cout << endl;
	z2.Coordenada::mostrar();

	return 0;
}
