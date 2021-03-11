#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int rn;
	int cn;
	int *e;
} matrix_t;

void free_matrix( matrix_t * );

matrix_t * make_matrix( int rn, int cn );

matrix_t * read_matrix( FILE *in );

void put_entry_matrix( matrix_t *, int i, int j, int val );

void add_to_entry_matrix( matrix_t *, int i, int j, double val );

int get_entry_matrix( matrix_t *, int i, int j );
