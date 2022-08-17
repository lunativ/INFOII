/*
 * estructuras.h
 *
 *  Created on: 15 may. 2019
 *      Author: lunat
 */

typedef struct ElementoLista{
	int Dato;
	struct ElementoLista * siguiente;
}Elemento;

typedef struct ListaUbicacion{
	 Elemento * inicio;
	int nro_elementos;
} Pila;

void inicializacion(Pila * p)
{
	p->inicio = NULL;
	p->nro_elementos = 0;
}

int push(Pila *p, int dato)
{
	Elemento * nuevo_elemento = (Elemento *) malloc(sizeof(Elemento));

	if(nuevo_elemento == NULL)
		return -1;
	else
	{
		nuevo_elemento->Dato = dato;
		nuevo_elemento->siguiente = p->inicio;
		p->inicio = nuevo_elemento;
		p->nro_elementos++;
		return p->nro_elementos;
	}
}

int pop(Pila *p)
{
	Elemento * sup_elemento;
	if(p->nro_elementos == 0)
		return -1;
	else
	{
		sup_elemento = p->inicio;
		int d = sup_elemento->Dato;
		p->inicio = p->inicio->siguiente;
		free(sup_elemento);
		p->nro_elementos--;
		return d;
	}
}

void mostrar(Pila *p){
	Elemento *actual;
	int i;
	actual = p->inicio;

	printf("Contenido de Pila: \n");
	for(i=0; i < p->nro_elementos; i++)
	{
		printf("%d, ",actual->Dato);
		actual = actual->siguiente;
	}

}

int estaVacia(Pila *p){
	if(p->nro_elementos == 0)
		return 1;
	else
		return 0;
}

