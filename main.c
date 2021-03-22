#include <stdio.h>
#include <stdlib.h>

#include "world/generations.h"

// 0 - dead
// 1 - alive
// 2 - dying
// 3 - breed

int main(int argc, char **argv) {
	if ( argc < 3 ) {
		fprintf( stderr, "Not enough arguments, please give:\n1.File name\n2.Number of Iterations\n" );
		return 1;
	}	

	int numberOfIterations = atoi(argv[2]);
	char *fileName = argv[1];

	if ( numberOfIterations < 1 ) { 
		fprintf( stderr, "The number of iterations must be bigger than 0\n" );
		return 2;
	}

	makeAutomata( fileName, numberOfIterations );

	return 0;
}
