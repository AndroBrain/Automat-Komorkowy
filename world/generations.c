#include "mat.h"
#include "neighbourhood.h"
#include "../savingFiles/output.h"

void fix_world(matrix_t *mat){
    for ( int r = 0; r < mat->rn; r++ )
        for ( int c = 0; c < mat->cn; c++ ){
            if ( get_entry_matrix( mat, r, c ) == 2 )
                put_entry_matrix( mat, r, c, 0 );
            else if ( get_entry_matrix( mat, r , c ) == 3 )
                put_entry_matrix( mat, r, c, 1 );
        }

}

void iterate ( char *fileName, int numberOfIterations ) {
	matrix_t *mat = read_matrix( fopen(fileName, "r") );
	for( int n = 1; n <= numberOfIterations; n++ ){
		createPbmFile( mat, n );
		for ( int r = 0; r < mat->rn; r++ )
			for ( int c = 0; c < mat->cn; c++ )
				moor( mat, r, c );

		fix_world( mat );
	}
	createPbmFile( mat, numberOfIterations );
}
