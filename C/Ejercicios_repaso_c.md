# Ejercicios de repaso de C

Gonzalo F. Perez Paina

## Ejercicicios

 1. Escribir un programa que calcule el promedio de $N$ números enteros.
     * Solicitar al usuario la cantidad de números a promediar ($N$).
     * Solicitar al usuario los $N$ valores enteros.
     * Calcular el promedio.
     * Imprimir el resultado del promedio.

     La interacción con el usuario a través de la entrada y salida estándar debe ser como se muestra a continuación:
     ```
     ./promedio1
     Ingrese la cantidad de números a promediar: 4
     Ingrese el entero 1: 12
     Ingrese el entero 2: 23
     Ingrese el entero 3: 32
     Ingrese el entero 4: 11
     El promedio es: 19.500000
     ```
     

 2. Modificar el programa anterior para que el programa no le solicite al usuario la cantidad de números a promediar, en su lugar el programa solicita los números enteros hasta ingresar el valor 0 (cero).

     

 3. Escribir una función que calcule el promedio de $N$ números enteros en base al siguiente prototipo
     ```c
     double promedio(int * , int );
     ```

     junto al programa que evalúe su correcto funcionamiento.
