#include <stdio.h>
#include <stdlib.h>
matrix_t *
make_matrix (int rn, int cn)
{
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

	void
free_matrix (matrix_t * m)
{
	free (m->e);
	free (m);
}

	void
put_entry_matrix (matrix_t * m, int i, int j, double val)
{
	if (i >= 0 && i < m->rn && j >= 0 && j <= m->cn)
		m->e[i * m->cn + j] = val;
}

	void
add_to_entry_matrix (matrix_t * m, int i, int j, double val)
{
	if (i >= 0 && i < m->rn && j >= 0 && j <= m->cn)
		m->e[i * m->cn + j] += val;
}

	double
get_entry_matrix (matrix_t * m, int i, int j )
{
	if (i >= 0 && i < m->rn && j >= 0 && j <= m->cn)
		return m->e[i * m->cn + j];
	else
		return -999;
}
double
get_entry_matrix (matrix_t * m, int i, int j )
{
	if (i >= 0 && i < m->rn && j >= 0 && j <= m->cn)
		return m->e[i * m->cn + j];
	else
		return -999;
}

	matrix_t *
read_matrix (FILE * in)
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
			if (fscanf (in, "%lf", &new_mat->e[i * cn + j]) != 1) {
				free_matrix (new_mat);
				return NULL;
			}

	return new_mat;
}

	void
write_matrix (matrix_t * m, FILE * out)
{
	int i, j;
	if (m == NULL) {
		fprintf (out, "Matrix is NULL\n");
		return;
	}

	fprintf (out, "%d %d\n", m->rn, m->cn);
	for (i = 0; i < m->rn; i++) {
		for (j = 0; j < m->cn - 1; j++)
			fprintf (out, "%8.5f ", m->e[i * m->cn + j]);
		fprintf (out, "%8.5f\n", m->e[i * m->cn + j]);
	}
}

