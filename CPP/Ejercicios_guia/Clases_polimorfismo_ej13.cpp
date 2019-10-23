//============================================================================
// Name        : Clases_polimorfismo_ej13.cpp
// Author      : VL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <cmath>

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



class Figura{
	Coordenada centro;
	int nroLados;
public:
	Figura(){nroLados = 0;}
	void setNroLados(int n){if(n>0) nroLados = n;}
	int getNroLados(void){return nroLados;}
	void setCentro(int x, int y){ centro.setX(x); centro.setY(y);}
	Coordenada getCentro(void){return centro;}
	virtual float Area() = 0;
	virtual int Perimetro() = 0;
};

class Rectangulo : public Figura{
	int base;
	int altura;
public:
	Rectangulo(){base = 0; altura = 0; this->setNroLados(4);}
	void setBase(int b){base = b;}
	void setAltura(int h){altura = h;}
	int getBase(void){return base;}
	int getAltura(void){return altura;}
	float Area(){return base*altura;}
	int Perimetro(){return base+base+altura+altura;}


};

class Triangulo : public Figura{
	int base;
	int altura;
public:
	Triangulo(){base = 0; altura = 0; this->setNroLados(3);}
	void setBase(int b){base = b;}
	void setAltura(int h){altura = h;}
	int getBase(void){return base;}
	int getAltura(void){return altura;}
	float Area(){return base*altura/2;}
	int Perimetro(){return base+sqrt((base/2)*(base/2)+(altura*altura))*2;}


};


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Rectangulo r;
	r.setAltura(3);
	r.setBase(2);
	cout<<"Area: "<<r.Area()<<" Perimetro: "<<r.Perimetro()<<endl;
	Triangulo t;
	t.setAltura(4);
	t.setBase(7);
	cout<<"Area: "<<t.Area()<<" Perimetro: "<<t.Perimetro()<<endl;

	return 0;
}
