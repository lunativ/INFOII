En esta carpeta incluyo codigos C y Python con ejemplos de codigo para generar señales y graficarlas en python y apertura de archivos en C y algunos procesamiento de señales básicos. 

Se propone implementar en lenguaje C los siguientes programas: 

1- Mediante funciones de manejo de archivos de alto nivel (fopen, fscanf, fclose) abrir y leer un archivo de texto que contiene en cada renglon un numero entero, calcular el promedio y valor RMS de los valores leidos. 

Probar el programa con los archivos de datos provistos en este directorio del repositorio que contienen:
senal.txt: señal senoidal
senal2.txt: señal senoidal con ruido agregado
datos_atip.txt: señal continua con ruido agregado

En el notebook Jupyter senales.ipynb se incluyen los codigos utilizados para generar estos archivos.

2- Modificar el programa anterior para utilizar funciones de manejo de archivo de bajo nivel. 

3- Implementar un filtro de media movil de orden 3 para reducir el ruido en las datos provistos. El programa en C deberá guardar un nuevo archivo de texto con los valores filtrados. 
Se pueden utilizar los mismos scripts de python para observar los resultados.
