#include <stdio.h>
#include <stdlib.h>

#include "mat.h"

// 0 - dead
// 1 - alive
// 2 - dying
// 3 - breed

void breedAndKill( matrix_t *mat, int row, int column, int alive );
void moor( matrix_t *mat, int row, int column );
void createPbmFile( matrix_t *mat, int number );
int isAlive( int state );
void fix_world(matrix_t *mat);

int main(int argc, char **argv) {
	matrix_t *mat;
	int numberOfIterations;
	

	if( argc > 0 ) 
		mat = read_matrix( fopen(argv[1], "r") );
	else 
		fprintf( stderr, "First argument must be name of a file with matrix");

	numberOfIterations = atoi(argv[2]);

	for( int n = 1; n <= numberOfIterations; n++ ){
		createPbmFile( mat, n );
		for ( int r = 0; r < mat->rn; r++ )
			for ( int c = 0; c < mat->cn; c++ )
				moor( mat, r, c );

		fix_world( mat );
	}
	createPbmFile( mat, numberOfIterations );

	return 0;
}

void moor(matrix_t *mat, int row, int column){
	int alive = 0;
	for ( int r = row - 1; r <= row + 1; r++ )
		for ( int c = column - 1; c <= column + 1; c++)
			if ( r >= 0 && r < mat->rn && c >= 0 && c < mat->cn && ( r != row || c != column)) 
				if ( isAlive( get_entry_matrix( mat, r, c ) ) == 1 )
					alive ++;
	breedAndKill( mat, row, column, alive);
}

int isAlive( int state ){
	if( state == 1 || state == 2) {
		return 1;
	}
	return 0;
}

void breedAndKill( matrix_t *mat, int row, int column, int alive) {
	int actualState = get_entry_matrix( mat, row, column );
	
	if( actualState == 0 )
		if( alive == 3 )
			put_entry_matrix( mat, row, column, 3);

	if( actualState == 1 )
		if( alive != 2 && alive != 3 )
			put_entry_matrix( mat, row, column, 2);
}

void createPbmFile( matrix_t *mat, int number ){
	char fileName[40];
	snprintf(fileName, sizeof fileName, "outputs/output%d.pbm", number);

	FILE *out = fopen( fileName, "wb" );
	fprintf( out, "P1\n" );
	fprintf( out, "%d %d\n", mat->rn, mat->cn );

	for(int r = 0; r < mat->rn; r++){
		for( int c = 0; c < mat->cn; c++)
			fprintf( out, "%d ", get_entry_matrix( mat, r, c ));
		fprintf( out, "\n" );
	}
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
