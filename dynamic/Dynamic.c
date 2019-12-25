#include <pthread.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>

extern int m;
extern int n;
extern int **matrix;

extern int thread_number;
struct Data
{
    unsigned int i1;
    unsigned int i2;
};

int thread_count;
pthread_mutex_t lock;

void Found_steps (struct Data *data)
{
    assert(data!=NULL);
    int step = m/thread_number;
    if (step>0) {
        for (unsigned int i = 0; i < thread_number; ++i) {
            data[i].i1 = i * step;
            data[i].i2 = data[i].i1 + step;
        }
    }
}

void *One_thread_display (void *args)
{
    struct Data *data = (struct Data*) args;
    assert (data);

    for (unsigned int i=data->i1, k=m-1-data->i1; i<data->i2; ++i, --k) {
        for (unsigned int j = 0, l = m - 1; l > i; ++j, --l) {
            int tmp = matrix[i][j];
            matrix[i][j] =  matrix[l][k];
            matrix[l][k] = tmp;
        }
    }
    pthread_mutex_init(&lock, NULL);
    pthread_mutex_lock(&lock);
    thread_count++;
    pthread_mutex_unlock(&lock);

    return 0;
}


void Display_matrix_threads ()
{

    pthread_t thread[thread_number];
    thread_count=0;

    struct Data data[thread_number];
    Found_steps(data);

    for (unsigned int i=0; i<thread_number; ++i)
    {
        struct Data *args = &(data[i]);

        assert (pthread_create(&(thread[i]), NULL, One_thread_display, (void*)args)==0);

        pthread_detach(thread[i]);
    }

    while (thread_count!=thread_number) {}
}
