#include <stdlib.h>

#include "mat.h"

void breedAndKill( matrix_t *mat, int row, int column, int alive) {
	int actualState = get_entry_matrix( mat, row, column );

	if( actualState == 0 )
		if( alive == 3 )
			put_entry_matrix( mat, row, column, 3);

	if( actualState == 1 )
		if( alive != 2 && alive != 3 )
			put_entry_matrix( mat, row, column, 2);
}

int isAlive( int state ){
	if( state == 1 || state == 2) {
		return 1;
	}
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
