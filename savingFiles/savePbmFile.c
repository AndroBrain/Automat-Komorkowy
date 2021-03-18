#include "output.h"

void savePbmFile( matrix_t *mat, int number ){
	char fileName[40];

	snprintf(fileName, sizeof fileName, "outputs/output%d.pbm", number);

	FILE *out = fopen( fileName, "wb" );
	fprintf( out, "P1\n" );

	save_matrix( mat, out, 2 );

	saveLastIteration( mat );
}
