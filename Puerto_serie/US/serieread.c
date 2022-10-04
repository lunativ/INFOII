#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>

int main (void)
{
	char dato;
	int fd;
	char s[20];
	int i = 0;
	int d = 0;
	speed_t baud = B9600;

	printf("Inicio \n");
	fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY );
	if (fd == -1)
	{
		printf("error !! \n");
		return -1;
	}

	struct termios settings;
	tcgetattr(fd,&settings);
	cfsetospeed(&settings, baud); /* baud rate */
	settings.c_cflag &= ~PARENB; /* no parity */
	settings.c_cflag &= ~CSTOPB; /* 1 stop bit */
	settings.c_cflag &= ~CSIZE;
	settings.c_cflag |= CS8 | CLOCAL; /* 8 bits */
	//settings.c_lflag = ICANON; /* canonical mode */
	//settings.c_oflag &= ~OPOST; /* raw output */

	tcsetattr(fd, TCSANOW, &settings); /* apply the settings */
	tcflush(fd, TCOFLUSH);
	
		
	i = 0 ;
	for(i = 0; i<10;i++)
	{
		//printf("\n%d: ",i);
		//printf("escribir %s \n",s);
		//write (fd, &s, 2);

		for(d = 0; d<10000;d++)
		{;}		
		tcflush(fd, TCOFLUSH);
		int n = read(fd, s, 15);
		s[n+1]=0;
		if (n>0){
		   //printf("\nRecibido: %d bytes :  %s", n,s);
		   if (n == 15)
		   {
		      printf("\n%d",atoi(&s[10]));
		   }
		
		}
		
		

	}



	close(fd);
	printf("\nPuerto cerrado");
	return 0;
}
