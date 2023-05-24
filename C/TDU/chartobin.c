/**
 * @file chartobin.c
 * @author Valentin Lunati (lunativ@gmail.com)
 * @brief Funcion para mostrar en consola (stdout) la representacion
 * binaria de un numero entero recibido como argumento (1 cifra)
 * @version 0.1
 * @date 2022-06-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
int main(int argc, char *argv[])
{
  
  if ((argc < 2)|| (argc > 2))
  {
    fprintf(stderr, "MODO DE USO: %s <char>\n", argv[0]);
    return 1;
  }
  
  char valor = *argv[1];
  for (int i = sizeof(char) * 7; i >= 0; i--)
    printf("%d", (valor & (1 << i)) >> i );
  putc('\n', stdout);
  return 0;
}