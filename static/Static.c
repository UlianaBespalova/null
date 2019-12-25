#include "Static.h"

void Display_matrix (int **matrix, int m)
{
    for (int i=0, k=m-1; i<m; ++i, k--) {
        for (int j = 0, l = m - 1; l > i; ++j, --l) {
            int tmp = matrix[j][i];
            matrix[j][i] = matrix[k][l];
            matrix[k][l] = tmp;
        }
    }
}
