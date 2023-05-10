# Ejercicios de repaso de Lenguaje C parte 2

1)  	Escribir las declaraciones apropiadas y asignar los valores iniciales dados para cada grupo de variables y arreglos:
```
	a.       Variables de coma flotante: a = -8.2, b = 0.005
	b.       Variables enteras: x = 129, y = 87, z = -22
	c.       Variables de carácter: c1 = w, c2 = &
	d.       Variables de doble precisión: d1 = 2.88 x 10-8, d2 = -8.4 x 105
	e.       Variables enteras: u = 711 (octal), v = fa123 (hexadecimal)
	f.        Variable entera larga: grande = 123465789
	g.       Variable de doble precisión: c = 0.333333333
	h.       Variable de carácter: eol = carácter de nueva línea
	i.         Arreglo unidimensional de caracteres: mensaje = “Error!”
```

2) Sea A una matriz de tamaño nxn, implemente un programa que dado un menú de opciones resuelva:

	a.       La transpuesta de A (At).
	
	b.       Determine si A es simétrica o antisimétrica.
	
	c.       Determine si A es una matriz triangular superior o triangular inferior.



3) Crear una función que determine la longitud de una cadena de caracteres (mismo funcionamiento que la funcion strlen de string.h)

4) Escribir una función que reciba como argumento un arreglo de caracteres y lo devuelva invertido con la interfaz:
```
void string_reverse(char  * c);
```

5) Escribir una función que reciba una cadena de caracteres s y un arreglo de caracteres con espacio suficiente t, y copie la cadena en el arreglo, terminando la cadena con el caracter ’\0’ (funcion strcpy() de la biblioteca ): void strcpy(char *t, const char *s);

6) Crear una función que concatena dos cadenas (cadena 1 y cadena 2) dejando el resultado de dicha operación sobre la primera (cadena 1). 

7) Escribir el cuerpo de la función `float2str` del siguiente programa:

     ```c
     #include <stdio.h>
     #include <stdlib.h>
     #include <math.h>
     
     #define LONGITUD 10
     
     void float2str(float , char * );
     
     int main(void)
     {
         float val;
         char cad[LONGITUD];
     
         val = 3.14;
         float2str(val, cad);
         printf("%s\n", cad);
     
         val = 1.75;
         float2str(val, cad);
         printf("%s\n", cad);
     
         return 0;
     }
     
     void float2str(float val, char *cad)
     {
         /* Completar */
     }
     ```

     La función `float2str` convierte la variable de punto flotante (`float`) `val` a una cadena de caracteres `cad`. El valor a convertir es siempre positivo de `0.00` hasta `9.99`. La implementación de la función no debe hacer uso de las funciones de biblioteca de caracteres y cadenas. (Ejercicio del profe Perez Paina)



8) Ejecutar el siguiente codigo:
 - Analizar el ambito de las variables utilizadas
 - Evaluar los cambios en performance (tiempo de ejecucion y consumo de memoria segun los tipos de variables a utilizar)
```
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
```

9) Cargar en un vector de cadenas de caracteres un listado de los nombres de hasta 10 alumnos, ordenarlos alfabéticamente y mostrarlos en pantalla.
10) Cargar los datos de nombre y 3 notas de hasta 10 alumnos. Mostrar en pantalla el listado de nombres ordenado alfabéticamente junto a la nota promedio de cada alumno.
11) Cargar los mismos datos anteriores utilizando una estructura adecuada para almacenar los datos.

Referencia sobre metodos de ordenamiento: https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Algoritmos_y_Estructuras_de_Datos
