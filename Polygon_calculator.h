#ifdef __cplusplus
extern "C"
#endif

#ifndef IV_POLYGON_CALCULATOR_H
#define IV_POLYGON_CALCULATOR_H

#ifdef __cplusplus
extern "C"
{double Get_value(char *str);

void Coordinates_input (const int n, double *arr_x, double *arr_y);

double Polygon_square(const int n, const double *arr_x, const double *arr_y);

double Polygon_calculator();}
#endif

double Get_value(char *str);

void Coordinates_input (const int n, double *arr_x, double *arr_y);

double Polygon_square(const int n, const double *arr_x, const double *arr_y);

double Polygon_calculator();

#endif //IV_POLYGON_CALCULATOR_H
