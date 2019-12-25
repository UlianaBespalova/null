#include <stdio.h>
#include <stdlib.h>

#include <Static.h>
#include <Dynamic.h>

void show (int **matr, int nn, int mm)
{
    for (int i=0; i<mm; ++i)
    {
        for (int j = 0; j < nn; ++j)
           printf  ("%d ", matr[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {

    m=5;
    n=5;

    matrix = (int**)malloc(m* sizeof(int*));
    for (int i=0; i<m; i++) matrix[i]=malloc(sizeof(int)*n);

    for (unsigned int i=0; i<m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrix[i][j] = rand()%100;
        }
    }

    show(matrix, n, m);
    Display_matrix_threads();
    show(matrix, n, m);






    return 0;
}
