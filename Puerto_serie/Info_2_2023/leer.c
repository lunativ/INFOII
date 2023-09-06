#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "termset.h"


int main() {
 
 int fd; //file descriptor
 struct termios oldtty, newtty;
 
 char buffer[20];
 int s;
 char port[]="/dev/ttyS5";
 
 fd= open(port,O_RDWR | O_NOCTTY | O_NDELAY);
 if(fd==-1){
  printf("ERROR: unable to open %s\n",port);
  return -1;
 }
 if(termset(fd, 9600, &oldtty, &newtty) == -1)
{
  printf("ERROR: unable to configure port %s\n",port);
  return -1;
 }

 
 while(1){
	 s = read(fd,buffer,sizeof(buffer));
	 printf("Datos recibidos: %s \n",buffer);;
 }
 close(fd);
 
 return 0;
}
