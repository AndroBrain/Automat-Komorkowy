#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mat.h"

matrix_t *make_matrix (int rn, int cn)
{
	if( rn <= 0 || cn <= 0 )
		return NULL;
	matrix_t *new_mat = malloc (sizeof *new_mat);
	if (new_mat == NULL)
		return NULL;
	if ((new_mat->e =
				malloc ((size_t) rn * (size_t) cn * sizeof *new_mat->e)) == NULL) {
		free (new_mat);
		return NULL;
	}
	new_mat->rn = rn;
	new_mat->cn = cn;
	memset (new_mat->e, 0, (size_t) (rn * (size_t) cn * sizeof *new_mat->e));
	return new_mat;
}

void free_matrix (matrix_t * m)
{
	free (m->e);
	free (m);
}

void put_entry_matrix (matrix_t * m, int i, int j, int val)
{
	if (i >= 0 && i < m->rn && j >= 0 && j <= m->cn)
		m->e[i * m->cn + j] = val;
}

void add_to_entry_matrix (matrix_t * m, int i, int j, double val)
{
	if (i >= 0 && i < m->rn && j >= 0 && j <= m->cn)
		m->e[i * m->cn + j] += val;
}

int get_entry_matrix (matrix_t * m, int i, int j )
{
	if (i >= 0 && i < m->rn && j >= 0 && j <= m->cn)
		return m->e[i * m->cn + j];
	else
		return -999;
}

matrix_t *read_matrix (FILE * in)
{
	int rn, cn;
	int i, j;
	matrix_t *new_mat;
	if (fscanf (in, "%d %d", &rn, &cn) != 2)
		return NULL;
	if ((new_mat = make_matrix (rn, cn)) == NULL)
		return NULL;
	for (i = 0; i < rn; i++)
		for (j = 0; j < cn; j++)
			if (fscanf (in, "%d", &new_mat->e[i * cn + j]) != 1) {
				free_matrix (new_mat);
				return NULL;
			}

	return new_mat;
}
