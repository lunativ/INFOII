//============================================================================
// Name        : Clases_ej11.cpp
// Author      : VL
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Vector
{
	int * v;
	int N;
public:
	Vector();
	int getP(int p){if(p >=0) return v[p]; else return 0;}
	void setP(int p, int d){if(p >=0) v[p]=d;}
	void cargar(void);
	void mostrar(void);
	int mayor(void);
	int menor(void);
	~Vector(){delete[] v;}
};

Vector::Vector(){
	N = 0;
	cout<<"Ingrese N: ";
	cin>> N;
	if(N >=0)
		v = new int[N];
	else
		v = NULL;
}

void Vector::cargar(void){
	cout<< "Ingrese valores: ";
	for(int i = 0; i<N; i++)
	{
		cout<<"\n"<<i<<": ";
		cin>> v[i];
	}
}

void Vector::mostrar(){
	cout<<"\nVector: ";
	for(int i = 0; i<N; i++)
		{
			cout<<v[i]<<", ";
		}
	cout<< endl;
}

int Vector::mayor(void){
	int pm = 0;
	for(int i = 1; i<N; i++)
	{
		if(v[i] > v[pm])
			pm = i;

	}
	return pm;

}

int Vector::menor(void){
	int pm = 0;
	for(int i = 1; i<N; i++)
	{
		if(v[i] < v[pm])
			pm = i;

	}
	return pm;

}
int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Vector v1;
	v1.cargar();
	v1.mostrar();
	cout<<"Elemento mayor: "<< v1.getP(v1.mayor())<<endl;
	cout<<"Elemento menor: "<< v1.getP(v1.menor())<<endl;
	return 0;
}
