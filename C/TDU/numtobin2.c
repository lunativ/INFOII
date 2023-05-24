/**
 * @file numtobin2.c
 * @author Valentin Lunati (lunativ@gmail.com)
 * @brief Funcion para mostrar en consola (stdout) la representacion
 * binaria de un numero entero recibido como argumento
 * @version 0.2
 * @date 2022-06-15
 * 
 * 
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
  
  char valor = atoi(argv[1]); /** valor recibido como argumento convertido a char */
  printf("%c%c%c%c%c%c%c%c",
   (valor&0x80)?'1':'0',
   (valor&0x40)?'1':'0',
   (valor&0x20)?'1':'0',
   (valor&0x10)?'1':'0',
   (valor&0x08)?'1':'0',
   (valor&0x04)?'1':'0',
   (valor&0x02)?'1':'0',
   (valor&0x01)?'1':'0'
  );
  putc('\n', stdout);
  return 0;
}