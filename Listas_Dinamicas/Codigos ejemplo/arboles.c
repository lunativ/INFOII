/*
 ============================================================================
 Name        : arboles.c
 Author      : VL
 Version     :
 Copyright   : VL
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct nodoArbol
{
	struct nodoArbol *ptrIzq;
	int dato;
	struct nodoArbol *ptrDer;
};

typedef struct nodoArbol NodoArbol;
typedef NodoArbol *ptrNodoArbol;

/*prototipos*/
void insertarNodo(ptrNodoArbol *ptrArbol, int valor);
void inOrden(ptrNodoArbol ptrArbol);
void preOrden(ptrNodoArbol ptrArbol);
void postOrden(ptrNodoArbol ptrArbol);

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	int valor;
	ptrNodoArbol ptrRaiz = NULL;

	srand(time(NULL));
	puts("Cargar numeros en un arbol: ");

	   // insert random values between 0 and 14 in the tree
	   for (unsigned int i = 1; i <= 20; ++i) {
	      int item = rand() % 15;
	      printf("%3d, ", item);
	      insertarNodo(&ptrRaiz, item);
	   }



	//recorrer y mostrar los elementos:
	printf("\nRecorrido en orden:\n");
	inOrden(ptrRaiz);
	printf("\nRecorrido en pre orden:\n");
	preOrden(ptrRaiz);
	printf("\nRecorrido en post orden:\n");
	postOrden(ptrRaiz);


	return EXIT_SUCCESS;
}

void insertarNodo(ptrNodoArbol *ptrArbol, int valor)
{
	//Si el arbol esta vacio-> este es el nodo raiz (o un padre)
	if(*ptrArbol == NULL)
	{
		*ptrArbol = malloc(sizeof(NodoArbol));
		if(*ptrArbol != NULL)//memoria ok
		{
			(*ptrArbol)->dato = valor;
			(*ptrArbol)->ptrDer = NULL;
			(*ptrArbol)->ptrIzq = NULL;
		}
		else
		{printf("No hay memoria disponible. \n");}

	}
	else//si el arbol no esta vacio el nodo es un hijo, debo determinar si es hijo izq o der
	{
		if (valor < (*ptrArbol)->dato)
		{
			insertarNodo(&((*ptrArbol)->ptrIzq),valor);
		}
		else
			if (valor > (*ptrArbol)->dato)
			{
				insertarNodo(&((*ptrArbol)->ptrDer),valor);
			}
			else
			{printf("Valor ya existente.\n");}
	}
}



void inOrden(ptrNodoArbol ptrArbol)
{
   // si el arbol no es vacio lo puedo recorrer o es NULL cuando llego a un nodo final u hoja
   if (ptrArbol != NULL) {
	  inOrden(ptrArbol->ptrIzq);

	  //if(ptrArbol->dato > 7) si solo quiero mostrar los mayores a 7
	  	  printf("%3d", ptrArbol->dato);


      inOrden(ptrArbol->ptrDer);
   }
}


void preOrden(ptrNodoArbol ptrArbol)
{
	// si el arbol no es vacio lo puedo recorrer o es NULL cuando llego a un nodo final u hoja
   if (ptrArbol != NULL) {
      printf("%3d", ptrArbol->dato);
      preOrden(ptrArbol->ptrIzq);
      preOrden(ptrArbol->ptrDer);
   }
}


void postOrden(ptrNodoArbol ptrArbol)
{
	// si el arbol no es vacio lo puedo recorrer o es NULL cuando llego a un nodo final u hoja
   if (ptrArbol != NULL) {
	   postOrden(ptrArbol->ptrIzq);
	   postOrden(ptrArbol->ptrDer);
      printf("%3d", ptrArbol->dato);
   }
}

