/*
 ============================================================================
 Name        : Pilas_Colas.c
 Author      : VL
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"



int main(void) {

	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	Pila * p = (Pila *) malloc(sizeof(Pila));
	inicializacion(p);

	int numero;

	printf ("ingresa n�meros positivos, termina con 1\n");

	scanf("%d",&numero);

	while (numero!=-1)
	{

	push(p,numero);

	scanf("%d",&numero);

	}
	mostrar(p);
	printf("\nMostrar en orden inverso: ");
	while (!estaVacia(p)) printf("%d ",pop(p));
	printf("\n");
	mostrar(p);

	//Invertir la pila utilizando pilas auxiliares
/*

	Pila * aux1;
	Pila * aux2;
	aux1 = (Pila *) malloc(sizeof(Pila));
	inicializacion(aux1);
	aux2 = (Pila *) malloc(sizeof(Pila));
	inicializacion(aux2);

	while (!estaVacia(p))

	    push(aux1,pop(p));

	while (!estaVacia(aux1))

	    push(aux2,pop(aux1));

	while (!estaVacia(aux2))

	push(p,pop(aux2));

	mostrar(p);
*/


	return EXIT_SUCCESS;
}
