# Ejercicios de repaso de Lenguaje C parte 2

1)  	Escribir las declaraciones apropiadas y asignar los valores iniciales dados para cada grupo de variables y arreglos:
a.       Variables de coma flotante: a = -8.2, b = 0.005
b.       Variables enteras: x = 129, y = 87, z = -22
c.       Variables de carácter: c1 = w, c2 = &
d.       Variables de doble precisión: d1 = 2.88 x 10-8, d2 = -8.4 x 105
e.       Variables enteras: u = 711 (octal), v = fa123 (hexadecimal)
f.        Variable entera larga: grande = 123465789
g.       Variable de doble precisión: c = 0.333333333
h.       Variable de carácter: eol = carácter de nueva línea
i.         Arreglo unidimensional de caracteres: mensaje = “Error!”


2) Sea A una matriz de tamaño nxn, implemente un programa que dado un menú de opciones resuelva:
a.       La transpuesta de A (At).
b.       Determine si A es simétrica o antisimétrica.
c.       Determine si A es una matriz triangular superior o triangular inferior.


3) Crear una función que determine la longitud de una cadena de caracteres (mismo funcionamiento que la funcion strlen de string.h)
2)      Escribir una función que reciba como argumento un arreglo de caracteres y lo devuelva invertido con la interfaz:
void string_reverse(char  * c);

3) Escribir una función que reciba una cadena de caracteres s y un arreglo de caracteres con espacio suficiente t, y copie la cadena en el arreglo, terminando la cadena con el caracter ’\0’ (funcion strcpy() de la biblioteca ): void strcpy(char *t, const char *s);

4) Ejecutar el siguiente codigo:
 - Analizar el ambito de las variables utilizadas
 - Evaluar los cambios en performance (tiempo de ejecucion y consumo de memoria segun los tipos de variables a utilizar)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int fibonacciTerm(int n)
{
   int a=0, b=1, c;
   for(int i=1; i<n; i++)
   {
     c = a+b;
     a = b;
     b = c;
   }
   return a;
}

int main(int argc, char *argv[])
{
   int term, result,i;
  // system("clear");
  
  if (argc < 2)
  {
   printf("Ingrese el termino requerido de la serie de Fibonacci: ");
   scanf("%d", &term);
  }
  else{
	  term = atoi(argv[1]);
  }
	clock_t begin = clock();
	for(i = 0; i<10000;i++)
	   result = fibonacciTerm(term);
	clock_t end = clock();
	double time_spent = (double)(end - begin); //in microseconds
   printf("El termino requerido es: %d\n", result);
   printf("El tiempo de computo fue: %f\n", time_spent);

   return 0;
}
