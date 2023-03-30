#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int WIDTH = 105;
int HEIGHT = 30;

typedef struct {
	int xpos, ypos;
	int xdir, ydir;
} p;

int xpos=15, ypos=35;
int xdir=1, ydir=2;

void draw( void ) {
	int a, b;
	for (a = 0; a < WIDTH; ++a) {
		printf("X");
	}
	printf("\n");
	for (a = 0; a < HEIGHT; ++a) {
		for (b = 0; b < WIDTH; ++b) {
			if (b == WIDTH-1 || b == 0) {
				printf("X");
			}
			else if (a == xpos && b == ypos) {
				printf("o");
			}
			else {
				printf(" "); 
			}
		}
		printf("\n");
	}
	for (a = 0; a < WIDTH; ++a) {
		printf("X");
	}
	printf("\n");

	if (xpos == HEIGHT || xpos == 0) {
		xdir *= -1;
	}
	if (ypos == WIDTH || ypos == 1) {
		ydir *= -1;
	}

	xpos += xdir;
	ypos += ydir;
}

int main(int argc, char **argv) {
	// if (argc != 5 || )	
	while (1) {
		printf("\033[H\033[J");
		draw();
		usleep(51000);
	}
}
