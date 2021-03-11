#include "../world/mat.h"

void write_matrix (matrix_t * m, FILE * out) {
	int i, j;
	if (m == NULL) {
		fprintf (out, "Matrix is NULL\n");
		return;
	}

	fprintf (out, "%d %d\n", m->rn, m->cn);
	for (i = 0; i < m->rn; i++) {
		for (j = 0; j < m->cn - 1; j++)
			fprintf (out, "%d ", m->e[i * m->cn + j]);
		fprintf (out, "%d\n", m->e[i * m->cn + j]);
	}
}

void saveLastIteration( matrix_t *mat ) {
	FILE *out = fopen( "last.txt", "w" );
	write_matrix( mat, out );
}

void createPbmFile( matrix_t *mat, int number ){
	char fileName[40];

	snprintf(fileName, sizeof fileName, "outputs/output%d.pbm", number);

	FILE *out = fopen( fileName, "wb" );
	fprintf( out, "P1\n" );

	write_matrix( mat, out );	

	saveLastIteration( mat );
}
