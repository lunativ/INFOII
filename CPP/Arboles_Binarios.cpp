//============================================================================
// Name        : Arboles_Binarios.cpp
// Author      : vl
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


/*---------  Estructura del arbol  -------*/
typedef struct nodo{
     int dato;
     struct nodo *izq, *der;
}*ABB;


ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->dato = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}


void insertar(ABB &arbol, int x)
{

     if(arbol==NULL)
     {
           arbol = crearNodo(x);
           cout<<"\n\t  Insertado..!"<<endl<<endl;
     }
     else if(x < arbol->dato)
          insertar(arbol->izq, x);
     else if(x > arbol->dato)
          insertar(arbol->der, x);
     else
     {
    	 cout<<"El elemento ya existe"<<endl;

     }

}

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";


     cout<< arbol->dato <<endl;

     verArbol(arbol->izq, n+1);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->dato <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->dato << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          enOrden(arbol->der);
          cout << arbol->dato << " ";
     }
}


int main() {
	int dato;
	ABB arbol = NULL;
	cout << "Creando arbol:" << endl; // prints !!!Hello World!!!
	for(int i = 0; i<10; i++)
	{
		cout<<"Ingrese elemento "<<i<<": ";
		cin>>dato;
		insertar( arbol, dato);

	}
	cout<<"Mostrar arbol completo:"<<endl;
	verArbol(arbol, 0);
	cout<<endl;
	cout<<"Mostrar arbol en pre orden:"<<endl;
	preOrden(arbol);
	cout<<endl;
	cout<<"Mostrar arbol en orden:"<<endl;
	enOrden(arbol);
	cout<<endl;
	cout<<"Mostrar arbol en post orden:"<<endl;
	postOrden(arbol);
	return 0;
}
