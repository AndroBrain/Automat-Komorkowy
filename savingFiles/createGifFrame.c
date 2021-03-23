#include "../world/mat.h"
#include "gifMaker/gifenc.h"

void createGifFrame(matrix_t *mat, ge_GIF *gif) {
    for(int r = 0; r < mat->rn; r++)
        for(int c = 0; c < mat->cn; c++)
            gif->frame[mat->cn * r + c] = get_entry_matrix(mat, r, c);
    ge_add_frame(gif,10);
}
