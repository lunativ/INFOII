#include <stdio.h>
#include <stdlib.h>

#define MUESTRAS 256

int main() {
    FILE *archivo;
    double senal[MUESTRAS];
    double suma = 0;
    double promedio;
    int i;

    // Abrir el archivo
    archivo = fopen("senal.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    // Leer los datos del archivo
    for (i = 0; i < MUESTRAS; i++) {
        fscanf(archivo, "%lf", &senal[i]);
        suma += senal[i];
    }

    // Cerrar el archivo
    fclose(archivo);

    // Calcular el promedio
    promedio = suma / MUESTRAS;

    // Mostrar el resultado
    printf("El promedio de la señal es: %lf\n", promedio);

    return 0;
}
