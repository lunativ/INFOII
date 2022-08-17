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

	//Ingreso elementos
	push(p,1);
	push(p,2);
	push(p,3);
	push(p,4);

	mostrar(p);

	pop(p);
	pop(p);
	pop(p);

	mostrar(p);




	return EXIT_SUCCESS;
}
