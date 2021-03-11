#include "../world/mat.h"

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
