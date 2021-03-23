#include "../world/mat.h"
#include "saveMat.h"
#include "savePbmFile.h"
#include "../gifMaker/gifenc.h"

void saveLastIteration( matrix_t *mat ) {
	FILE *out = fopen( "last.txt", "w" );
	save_matrix( mat, out, 1 );
	fclose(out);
}

void save(matrix_t *mat, int numberOfIterations){
	savePbmFile(mat, numberOfIterations);
}

void saveGif(matrix_t *mat, ge_GIF *gif) {
	for(int r = 0; r < mat->rn; r++)
		for(int c = 0; c < mat->cn; c++)
			gif->frame[mat->cn * r + c] = get_entry_matrix(mat, r, c);	
	ge_add_frame(gif,10);
}
