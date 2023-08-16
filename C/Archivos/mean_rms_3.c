#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MUESTRAS 100
#define ORDEN 3

int main(int argc, char *argv[]) {
    FILE *archivo;
    double senal[MUESTRAS];
    double senal_filtrada[MUESTRAS];
    double suma = 0;
    double suma_cuadrados = 0;
    double promedio;
    double rms;
    int i, j;

    // Verificar que se haya especificado el nombre del archivo
    if (argc < 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        exit(1);
    }

    // Abrir el archivo
    archivo = fopen(argv[1], "r");
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

    // Calcular el promedio y el valor RMS de la señal original
    promedio = suma / MUESTRAS;
    rms = sqrt(suma_cuadrados / MUESTRAS);

    // Mostrar los resultados de la señal original
    printf("Señal original:\n");
    printf("  Promedio: %lf\n", promedio);
    printf("  Valor RMS: %lf\n", rms);

    // Aplicar el filtro de media móvil
    for (i = ORDEN; i < MUESTRAS - ORDEN; i++) {
        suma = 0;
        for (j = -ORDEN; j <= ORDEN; j++) {
            suma += senal[i+j];
        }
        senal_filtrada[i] = suma / (2 * ORDEN + 1);
    }

    // Calcular el promedio y el valor RMS de la señal filtrada
    suma = 0;
    suma_cuadrados = 0;
    for (i = ORDEN; i < MUESTRAS - ORDEN; i++) {
        suma += senal_filtrada[i];
        suma_cuadrados += senal_filtrada[i] * senal_filtrada[i];
    }
    promedio = suma / (MUESTRAS-6);
    rms = sqrt(suma_cuadrados / (MUESTRAS-6));

    // Mostrar los resultados de la señal filtrada
    printf("Señal filtrada:\n");
    printf("  Promedio: %lf\n", promedio);
    printf("  Valor RMS: %lf\n", rms);

    return 0;
}
