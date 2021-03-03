#include <stdlib.h>

typedef struct {
	int rn;
	int cn;
	double *e;
} matrix_t;

void free_matrix( matrix_t * );

matrix_t * make_matrix( int rn, int cn );

matrix_t * read_matrix( FILE *in );

void write_matrix( matrix_t *, FILE *out );

void put_entry_matrix( matrix_t *, int i, int j, double val );

void add_to_entry_matrix( matrix_t *, int i, int j, double val );

double get_entry_matrix( matrix_t *, int i, int j );
