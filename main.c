#include <stdio.h>
#include <stdlib.h>

#include "world.h"

int main(int argc, char **argv) {
	/* Opcje
	** argv[2] == Moor lub M
	** to jest 8 wokół z przekątnymi
	** argv[2] == Neumann lub N
	** to jest 4 wokół BEZ przekątnych
	*/
	matrix_t *mat;
	if( argc > 0 ) 
		mat = read_matrix( fopen(argv[1], "r") );
	write_matrix( mat, stdout );


	return 0;
}
