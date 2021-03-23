#include "mat.h"
#include "games.h"
//Jeśli martwa komórka otoczona przez 3 żywe to rodzi się
//Jeśli żywa komórka otoczona przez mniej niż 2 żywe i więcej niż 3 żywe to umiera
void breedAndKill( matrix_t *mat, int row, int column, int alive) {
	int actualState = get_entry_matrix( mat, row, column );

	if( actualState == 0 )
		if( alive == 3 )
			put_entry_matrix( mat, row, column, 3);

	if( actualState == 1 )
		if( alive != 2 && alive != 3 )
			put_entry_matrix( mat, row, column, 2);
		
}
