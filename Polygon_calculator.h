#ifdef __cplusplus
extern "C"
#endif

#ifndef IV_POLYGON_CALCULATOR_H
#define IV_POLYGON_CALCULATOR_H


double Get_value(char *str);

void Coordinates_input (const int n, double *arr_x, double *arr_y);

double Polygon_square(const int n, const double *arr_x, const double *arr_y);

double Polygon_calculator();

int Pol (int, int, int);

#endif //IV_POLYGON_CALCULATOR_H
