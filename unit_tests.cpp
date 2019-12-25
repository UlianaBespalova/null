#include "gtest/gtest.h"
#include <chrono>
#include <Static.h>
#include <Dynamic.h>


class DisplayMatrix: public::testing::Test
{
protected:
    void SetUp() override
    {
        n = 5;
        m = 5;

        matrix = (int**)malloc(m* sizeof(int*));
        for (int i=0; i<m; i++) matrix[i]=(int*)malloc(sizeof(int)*n);

        matrix_sample = (int**)malloc(m* sizeof(int*));
        for (int i=0; i<m; i++) matrix_sample[i]=(int*)malloc(sizeof(int)*n);

        for (int i=0; i<m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[i][j] = rand()%1000;
                matrix_sample[n-j-1][m-i-1] = matrix[i][j];
            }
        }
    }

    void TearDown() override
    {
        for (int i=0; i<m; i++) free (matrix[i]);
        free (matrix);
        for (int i=0; i<m; i++) free (matrix_sample[i]);
        free (matrix_sample);
    }

    int **matrix_sample;
};

class CompareAlgs: public::testing::Test
{
protected:
    void SetUp() override
    {
        n = 10000;
        m = 5000;

        matrix = (int**)malloc(m* sizeof(int*));
        for (int i=0; i<m; i++) matrix[i]=(int*)malloc(sizeof(int)*n);

        another_matrix = (int**)malloc(m* sizeof(int*));
        for (int i=0; i<m; i++) another_matrix[i]=(int*)malloc(sizeof(int)*n);

        for (unsigned int i=0; i<m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[i][j] = rand();
                another_matrix[i][j] = matrix[i][j];
            }
        }
    }

    void TearDown() override
    {
        for (int i=0; i<m; i++) free (matrix[i]);
        free (matrix);
        for (int i=0; i<m; i++) free (another_matrix[i]);
        free (another_matrix);
    }

    int **another_matrix;
};



TEST_F (DisplayMatrix, StaticLibraryDisplay)
{
    Display_matrix(matrix, m);
    EXPECT_EQ(matrix[0][0], matrix_sample[0][0]);
    EXPECT_EQ(matrix[2][2], matrix_sample[2][2]);
    EXPECT_EQ(matrix[4][1], matrix_sample[4][1]);
}

TEST_F (DisplayMatrix, DynamicLibraryDisplay)
{
    Display_matrix_threads();
    EXPECT_EQ(matrix[0][0], matrix_sample[0][0]);
    EXPECT_EQ(matrix[2][2], matrix_sample[2][2]);
    EXPECT_EQ(matrix[4][1], matrix_sample[4][1]);
}


TEST_F (CompareAlgs, CompareDisplayedMatrices)
{
    Display_matrix_threads();
    Display_matrix(another_matrix, m);
    EXPECT_EQ(matrix[0][0], another_matrix[0][0]);
    EXPECT_EQ(matrix[200][200], another_matrix[200][200]);
    EXPECT_EQ(matrix[4000][1000], another_matrix[4000][1000]);
    EXPECT_EQ(matrix[m-1][n-1], another_matrix[m-1][n-1]);
}


TEST_F (CompareAlgs, CompareTime)
{
    std::chrono::high_resolution_clock::time_point timeStart, timeFinish;

    int iter = 5;
    double naiveAlgTimer=0;
    double threadsAlgTimer=0;

    for (int i=0; i<iter; i++)
    {
        timeStart = std::chrono::high_resolution_clock::now();
        Display_matrix(another_matrix, m);
        timeFinish = std::chrono::high_resolution_clock::now();
        naiveAlgTimer+=(timeFinish-timeStart).count();
    }

    for (int i=0; i<iter; i++)
    {
        timeStart = std::chrono::high_resolution_clock::now();
        Display_matrix_threads();
        timeFinish = std::chrono::high_resolution_clock::now();
        threadsAlgTimer+=(timeFinish-timeStart).count();
    }
    printf("\nNaive_algorithm_time = %.3f\n", naiveAlgTimer/iter);
    printf("Threads_algorithm_time = %.3f\n\n", threadsAlgTimer/iter);
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

