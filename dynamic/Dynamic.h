#ifndef DYNAMIC_DYNAMIC_H
#define DYNAMIC_DYNAMIC_H

int m = 5000;
int n = 10000;
int **matrix;
int thread_number = 5;


#ifdef __cplusplus
extern "C"
{
struct Data;

void Found_steps(struct Data *);

void *One_thread_display(void *);

void Display_matrix_threads();
}
#endif



struct Data;

void Found_steps(struct Data *);

void *One_thread_display(void *);

void Display_matrix_threads();


#endif //DYNAMIC_DYNAMIC_H
