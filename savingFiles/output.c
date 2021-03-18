#include "../world/mat.h"
#include "saveMat.h"
#include "savePbmFile.h"

void saveLastIteration( matrix_t *mat ) {
	FILE *out = fopen( "last.txt", "w" );
	save_matrix( mat, out, 1 );
}

void save(matrix_t *mat, int numberOfIterations){
	savePbmFile(mat, numberOfIterations);
}
