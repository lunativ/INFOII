/*
 ============================================================================
 Name        : Colas.c
 Author      : VL
 Version     :
 Copyright   : VL
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Estructura autoreferenciada para nodo
struct nodoCola {
   char data; // define data as a char
   struct nodoCola *ptrSig; // nodoCola pointer
};

typedef struct nodoCola NodoCola;
typedef NodoCola *ptrNodoCola;

// function prototypes
void imprimirCola(ptrNodoCola currentPtr);
int estaVacia(ptrNodoCola ptrCabeza);
char desencolar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrCola);
void encolar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrCola, char value);


// function main begins program execution
int main(void)
{
	ptrNodoCola ptrCabeza = NULL; // initialize ptrCabeza
	ptrNodoCola ptrCola = NULL; // initialize ptrCola
	char item; // char input by user

	srand(time(NULL));
	puts("Cargar numeros en una pila: ");

	// insert random values between 0 and 14 in the tree
	for (unsigned int i = 1; i <= 10; ++i) {
		int item = rand() % 15;
		printf("%3d, ", item);
		encolar(&ptrCabeza, &ptrCola, item);
	}
	printf("\n");

	imprimirCola(ptrCabeza);


	puts("Fin.");
}



// insert a node at queue tail
void encolar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrCola, char value)
{
   ptrNodoCola newPtr = malloc(sizeof(NodoCola));

   if (newPtr != NULL) { // is space available
      newPtr->data = value;
      newPtr->ptrSig = NULL;

      // if empty, insert node at head
      if (estaVacia(*ptrCabeza)) {
         *ptrCabeza = newPtr;
      }
      else {
         (*ptrCola)->ptrSig = newPtr;
      }

      *ptrCola = newPtr;
   }
   else {
      printf("%c not inserted. No memory available.\n", value);
   }
}

// remove node from queue head
char desencolar(ptrNodoCola *ptrCabeza, ptrNodoCola *ptrCola)
{
   char value = (*ptrCabeza)->data;
   ptrNodoCola tempPtr = *ptrCabeza;
   *ptrCabeza = (*ptrCabeza)->ptrSig;

   // if queue is empty
   if (*ptrCabeza == NULL) {
      *ptrCola = NULL;
   }

   free(tempPtr);
   return value;
}

// return 1 if the queue is empty, 0 otherwise
int estaVacia(ptrNodoCola ptrCabeza)
{
   return ptrCabeza == NULL;
}

// print the queue
void imprimirCola(ptrNodoCola currentPtr)
{
   // if queue is empty
   if (currentPtr == NULL) {
      puts("Queue is empty.\n");
   }
   else {
      puts("The queue is:");

      // while not end of queue
      while (currentPtr != NULL) {
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->ptrSig;
      }

      puts("NULL\n");
   }
}

