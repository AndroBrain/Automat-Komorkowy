#include <stdio.h>
#include <stdlib.h>

#include "world.h"

// 0 - dead
// 1 - alive
// 2 - dying
// 3 - being born
void update( matrix_t *mat, int row, int column, int alive) {
	int actualState = get_entry_matrix( mat, row, column );
	if( actualState == 0 )
		if( alive == 3 )
			put_entry_matrix( mat, row, column, 3);
	if( actualState == 1 )
		if( alive != 2 || alive != 3 )
			put_entry_matrix( mat, row, column, 2);

}

void neumann(matrix_t *mat, int row, int column){
	int alive = 0;
	for( int r = row - 1; r <= row + 1; r++ )
		for( int c = column - 1; c <= column + 1; c++)
			if( r >= 0 && r < mat->rn && c >= 0 && c < mat->cn && ( r != row || c != column)) {
				int state = get_entry_matrix( mat, r, c);	
				if( state == 1 || state == 2) {
					alive++;
				}
			}
	update( mat, row, column, alive);
}

int main(int argc, char **argv) {
	/* Opcje
	 ** argv[2] == Moor lub M
	 ** to jest 8 wokół z przekątnymi
	 ** argv[2] == Neumann lub N
	 ** to jest 4 wokół BEZ przekątnych
	 ** podanie ilości iteracji
	 */
	matrix_t *mat;
	if( argc > 0 ) 
		mat = read_matrix( fopen(argv[1], "r") );

	write_matrix( mat, stdout );

	neumann( mat, 1, 1 );

	write_matrix( mat, stdout );
	return 0;
}
