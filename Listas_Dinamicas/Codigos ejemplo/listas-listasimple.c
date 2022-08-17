/*
 ============================================================================
 Name        : listas-listasimple.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct nodo
{
	char color[10];



	struct nodo *ptr;
};


struct nodo * CrearNodo(char * dato)
{
	struct nodo * pnodo = (struct nodo *) malloc(sizeof(struct nodo));
	if(pnodo != NULL)
	{
		strcpy(pnodo->color, dato);

		pnodo->ptr = NULL;
	}
	return pnodo;
}

void MostrarLista(struct nodo * pnodo)
{
	if(pnodo != NULL)
	{
		do
		{
			printf("%s, ", pnodo->color);

			pnodo = pnodo->ptr;
		}
		while(pnodo != NULL);

		printf("\n");
	}
}
int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//puntero para la direccion del primer elemento de la lista
	struct nodo * inicio;
	//puntero para referenciar el nodo a manipular
	struct nodo * pnodo;
	pnodo = CrearNodo("Rojo");
	inicio = pnodo;
	pnodo->ptr = CrearNodo("Verde");

	pnodo = pnodo->ptr;

	pnodo->ptr = CrearNodo("Azul");

	pnodo = pnodo->ptr;

	MostrarLista(inicio);

	return EXIT_SUCCESS;
}
