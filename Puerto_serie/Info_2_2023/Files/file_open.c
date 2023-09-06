#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int fd = open("datos.txt", O_RDWR | O_CREAT, 0777);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    char buf[BUFSIZ+1];
    ssize_t n = 0;
    while ((n = read(fd, buf, BUFSIZ)) > 0) {
        buf[n] = '\0';
        printf("Data: %s", buf);     
    }
    if (n == -1) {
        perror("read");
        exit(1);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(1);    
    }
    exit(0);
}
