#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MUESTRAS 256

int main() {
    FILE *archivo;
    double senal[MUESTRAS];
    double suma = 0;
    double suma_cuadrados = 0;
    double promedio;
    double rms;
    int i;

    // Abrir el archivo
    archivo = fopen("senal2.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    // Leer los datos del archivo
    for (i = 0; i < MUESTRAS; i++) {
        fscanf(archivo, "%lf", &senal[i]);
        suma += senal[i];
        suma_cuadrados += senal[i] * senal[i];
    }

    // Cerrar el archivo
    fclose(archivo);

    // Calcular el promedio y el valor RMS
    promedio = suma / MUESTRAS;
    rms = sqrt(suma_cuadrados / MUESTRAS);

    // Mostrar los resultados
    printf("El promedio de la señal es: %lf\n", promedio);
    printf("El valor RMS de la señal es: %lf\n", rms);

    return 0;
}
