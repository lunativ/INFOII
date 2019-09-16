Hola Joaquin, porque un codigo tan complicado? 
algo asi no te funciona?
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main (void)
{
	char dato;
	int fd;
	char s[2] = "a\n";
	int i = 0;


	fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY );
	if (fd == -1)
	{
		printf("error !! \n");
		return -1;
	}
	l = 0 ;
	for(;;)
	{
		printf("escribir %s \n",s);
		write (fd, &s, 2);
		for(i = 0; i<100000;i++)

	}



	close(fd);
	return 0;
}