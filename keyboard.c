#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include "keyboard.h"
//Masih gagal
static struct termios tOld, tNew;
void set_mode(int want_key)
{
	if (!want_key) {
		tcsetattr(STDIN_FILENO, TCSANOW, &tOld);
		return;
	}
 
	tcgetattr(STDIN_FILENO, &tOld);
	tNew = tOld;
	tNew.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &tNew);
}
 
int get_key()
{
	int c = 0;
	struct timeval tv;
	fd_set fs;
	tv.tv_usec = tv.tv_sec = 0;
 
	FD_ZERO(&fs);
	FD_SET(STDIN_FILENO, &fs);
	select(STDIN_FILENO + 1, &fs, 0, 0, &tv);
 
	if (FD_ISSET(STDIN_FILENO, &fs)) {
		c = getchar();
		set_mode(0);
	}
	return c;
}

void resetTermios()
{
	tcsetattr(0, TCSANOW, &tOld);
}
