#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Polygon_calculator.h"

double Get_value(char *str)
{
    char *ptr;
    double value;

    value = strtod(str, &ptr);
    if (*ptr != '\0') {
        printf("please, input number\n");
        return -1;
    }
    return value;
}

void Coordinates_input (const int n, double *arr_x, double *arr_y)
{
    if (!arr_x) {printf("Pointer 'x' is Null\n"); return;}
    if (!arr_y) {printf("Pointer 'y' is Null\n"); return;}

    int i;
    for (i = 0; i < n; i++)
    {
        char value_str[10];
        double value_x, value_y;

        scanf("%s9", value_str);
        value_x = Get_value(value_str);
        scanf("%s9", value_str);
        value_y = Get_value(value_str);

        arr_x[i] = value_x;
        arr_y[i] = value_y;
    }
}


double Polygon_square(const int n, const double *arr_x, const double *arr_y)
{
    double square = arr_x[n - 1] * arr_y[0] - arr_x[0] * arr_y[n - 1];

    int i;
    for (i=0; i<n-1; i++)
    {
        square = square + arr_x[i] * arr_y[i + 1] - arr_x[i + 1] * arr_y[i];
    }
    square = fabs(square / 2);
    return square;
}



double Polygon_calculator()
{
    char value_str[10];
    scanf("%s9", value_str);
    int n = (int)Get_value(value_str);

    if (n<3)
    {
        printf("the number of vertices must be more than 3\n");
        return 0;
    }

    double *arr_x = (double*)calloc(n, sizeof(double));
    double *arr_y = (double*)calloc(n, sizeof(double));
    Coordinates_input(n, arr_x, arr_y);

    double square = Polygon_square(n, arr_x, arr_y);

    free(arr_x);
    free(arr_y);

    return square;
}

