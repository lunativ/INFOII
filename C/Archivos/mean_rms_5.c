#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int archivo;
    double *senal;
    double suma = 0;
    double suma_cuadrados = 0;
    double promedio;
    double rms;
    int muestras, i, j;
    char buffer[1024];
    int bytes_leidos;

    // Verificar que se haya especificado el nombre del archivo y el número de muestras
    if (argc < 3) {
        printf("Uso: %s <nombre_archivo> <muestras>\n", argv[0]);
        exit(1);
    }

    // Obtener el número de muestras
    muestras = atoi(argv[2]);
    printf("Muestras: %d\n", muestras);

    // Crear el arreglo para almacenar los datos
    
    senal = (double *)malloc(muestras * sizeof(double));

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
    promedio = suma / muestras;
    rms = sqrt(suma_cuadrados / muestras);

    // Mostrar los resultados de la señal original
    printf("Señal original:\n");
    printf("  Promedio: %lf\n", promedio);
    printf("  Valor RMS: %lf\n", rms);

    // Liberar la memoria del arreglo
    free(senal);

    return 0;
}
