/*
 ============================================================================
 Name        : Pilas.c
 Author      : VL
 Version     :
 Copyright   : VL
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodoPila
{
	int dato;
	struct nodoPila *ptrSiguiente;
};

typedef struct nodoPila NodoPila;
typedef NodoPila * ptrNodoPila;

/*Prototipos*/
void push(ptrNodoPila *ptrCima, int info);//empujar, poner, insertar nodo
int pop(ptrNodoPila *ptrCima);//sacar, extraer, eliminar nodo
int estaVacia(ptrNodoPila ptrCima);
void imprimePila(ptrNodoPila ptrActual);

int a = 1;
int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int valor;
	ptrNodoPila ptrPila = NULL;


	srand(time(NULL));
	puts("Cargar numeros en una pila: ");

   // insert random values between 0 and 14 in the tree
   for (unsigned int i = 1; i <= 10; ++i) {
	  int item = rand() % 15;
	  printf("%3d, ", item);
	  push(&ptrPila, item);
   }
   printf("\n");

	imprimePila(ptrPila);


	return EXIT_SUCCESS;
}
void push(ptrNodoPila *ptrCima, int info)//push
{
	//insertar un nuevo dato en la pila:
	//crear un nuevo nodo

	//crear una variable con puntero a structura nodo:
	ptrNodoPila ptrNuevo;//puntero a nodo


	//Reservo memoria de manera dinamica
	ptrNuevo = (ptrNodoPila) malloc(sizeof(NodoPila));

	//inserto el nodo en la cima de la pila
	if(ptrNuevo != NULL)
	{
		ptrNuevo->dato = info;
		ptrNuevo->ptrSiguiente = *ptrCima;
		*ptrCima = ptrNuevo;
	}
	else
		printf("No hay memoria disponible.\n");

}

int pop(ptrNodoPila *ptrCima)// -> (NodoPila ** ptrcima)
{
	ptrNodoPila ptrTemp = *ptrCima;//guardo temporalmente el ultimo nodo

	int valor = (*ptrCima)->dato;//extraigo su informacion

	//actualizar el puntero a la cima de la pila
	*ptrCima = (*ptrCima)->ptrSiguiente;
	//libero memoria del nodo elimado
	free(ptrTemp);
	return valor;

}



void imprimePila(ptrNodoPila ptrActual)
{
	if(ptrActual == NULL)
	{
		printf("Pila vacia.\n");
	}
	else
	{
		printf("La pila es: ");

		while(ptrActual != NULL)//si nodo actual es nulo, he llegado al fin de la pila
		{
			printf("%d --> ", ptrActual->dato);
			ptrActual = ptrActual->ptrSiguiente;
		}
		printf("NULL\n");
	}
}
int estaVacia(ptrNodoPila ptrCima){return ptrCima == NULL;}


