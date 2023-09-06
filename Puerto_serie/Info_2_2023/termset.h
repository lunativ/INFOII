#ifndef TERMSET_H
#define TERMSET_H

#include <termios.h>
#include <fcntl.h>

struct termios ttyold, ttynew;

/* termset function
 * Parameters:
 *  fd: file descriptor -device- (ex: /dev/ttyUSB0)
 *  baudrate: communication speed (ex: 9600, 115200)
 *  ttyold: current termios structure
 *  ttynew: new termios structure
 */
int termset(int fd, int baudrate, 
  struct termios * ttyold, struct termios * ttynew);

#endif

