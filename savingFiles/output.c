#include "../world/mat.h"
#include "saveMat.h"
#include "savePbmFile.h"
#include "gifMaker/gifenc.h"
#include "createGifFrame.h"

void saveLastIteration( matrix_t *mat ) {
	FILE *out = fopen( "last.txt", "w" );
	save_matrix( mat, out, 1 );
	fclose(out);
}

void save(matrix_t *mat, int numberOfIterations){
	savePbmFile(mat, numberOfIterations);
}

void saveGif(matrix_t *mat, ge_GIF *gif) {
	createGifFrame(mat,gif);
}
