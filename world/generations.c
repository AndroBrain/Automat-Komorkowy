#include "mat.h"
#include "neighbourhood.h"
#include "../savingFiles/output.h"

void handleFileError() {
	fprintf( stderr, "File does not exist. Check given path\n" );	
	exit(1);
}

void fix_world(matrix_t *mat){
	for ( int r = 0; r < mat->rn; r++ )
		for ( int c = 0; c < mat->cn; c++ ){
			if ( get_entry_matrix( mat, r, c ) == 2 )
				put_entry_matrix( mat, r, c, 0 );
			else if ( get_entry_matrix( mat, r , c ) == 3 )
				put_entry_matrix( mat, r, c, 1 );
		}
}

void makeAutomata ( char *fileName, int numberOfIterations ) {
	FILE *in = fopen( fileName, "r" );
	if( in == NULL )
		handleFileError();

	matrix_t *mat = read_matrix( fopen(fileName, "r") );

	if ( mat == NULL ) 
		handleFileError();

	for( int n = 1; n <= numberOfIterations; n++ ){
		save( mat, n );
		for ( int r = 0; r < mat->rn; r++ )
			for ( int c = 0; c < mat->cn; c++ ) {
#ifdef NEUMANN	
				neumann( mat, r, c );
#else
				moor( mat, r, c );
#endif
			}
		fix_world( mat );
	}
	save( mat, numberOfIterations );
	free_matrix(mat);
	fprintf( stdout, "Program finished successfully\nGenerated file last.txt where position from last iteration is saved\n" );
}
