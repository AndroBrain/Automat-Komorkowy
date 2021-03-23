#include "mat.h"
#include "neighbourhood.h"
#include "../gifMaker/gifenc.h"
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

	matrix_t *mat = read_matrix( in );

	if ( mat == NULL ) {
		handleFileError();
		fclose(in);
	}

	ge_GIF *gif = ge_new_gif(
		"iterations.gif",
		mat->cn, mat->rn,
		(uint8_t []) {
            0x00, 0x00, 0x00, /* 0 -> black */
            0xFF, 0x00, 0x00, /* 1 -> red */
            0x00, 0xFF, 0x00, /* 2 -> green */
            0x00, 0x00, 0xFF, /* 3 -> blue */
		},
		2, 0
		);

	for( int n = 1; n <= numberOfIterations; n++ ){
		save( mat, n );
		saveGif( mat, gif);
		
		for ( int r = 0; r < mat->rn; r++ )
			for ( int c = 0; c < mat->cn; c++ ) {
#ifdef NEUMANN
				neumann( mat, r, c );
				fprintf(stdout, "HI");
#else
				moor( mat, r, c );
#endif
			}
		fix_world( mat );
	}
	save( mat, numberOfIterations );
	saveGif( mat, gif);

	saveLastIteration( mat );

	ge_close_gif(gif);

	free_matrix(mat);
	fclose(in);
	fprintf( stdout, "Program finished successfully\nGenerated file last.txt where position from last iteration is saved\n" );
}
