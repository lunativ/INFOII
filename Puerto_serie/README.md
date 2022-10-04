# Ejemplos de programacion con puerto serie en Linux y Arduino

en serie.c se muestra un ejemplo de un programa en C para linux que abre y configura el puerto serie "/dev/ttyUSB0" y recibe numeros desde el puerto serie. funciona con el ejemplo AnalogRead de Arduino

en la carpeta US se presenta un ejemplo de programa en Arduino para medir distancia con un sensor ultrasonico que envia la distancia en cm por puerto serie y dos programas en C que reciben ese dato y lo muestran en pantalla. En serieread_prom.c se promedian varias lecturas para corregir posibles errores de lectura debido a ruidos y evitar falsas lecturas.