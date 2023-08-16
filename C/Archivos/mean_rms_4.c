#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

#define MUESTRAS 100
#define ORDEN 3

int main(int argc, char *argv[]) {
    int archivo;
    double senal[MUESTRAS];
    double senal_filtrada[MUESTRAS];
    double suma = 0;
    double suma_cuadrados = 0;
    double promedio;
    double rms;
    int i, j;
    char buffer[1024];
    int bytes_leidos;

    // Verificar que se haya especificado el nombre del archivo
    if (argc < 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        exit(1);
    }

    // Abrir el archivo
    archivo = open(argv[1], O_RDONLY);
    if (archivo == -1) {
        printf("Error al abrir el archivo\n");
        exit(1);
    }

    // Leer los datos del archivo
    i = 0;
    while ((bytes_leidos = read(archivo, buffer, sizeof(buffer))) > 0) {
        for (j = 0; j < bytes_leidos; j++) {
            if (buffer[j] == '\n') {
                senal[i] = atof(buffer);
                suma += senal[i];
                suma_cuadrados += senal[i] * senal[i];
                i++;
            }
        }
    }

    // Cerrar el archivo
    close(archivo);

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
    for (i = 0; i < MUESTRAS; i++) {
        suma += senal_filtrada[i];
        suma_cuadrados += senal_filtrada[i] * senal_filtrada[i];
    }
    promedio = suma / MUESTRAS;
    rms = sqrt(suma_cuadrados / MUESTRAS);

    // Mostrar los resultados de la señal filtrada
    printf("Señal filtrada:\n");
    printf("  Promedio: %lf\n", promedio);
    printf("  Valor RMS: %lf\n", rms);

    return 0;
}
