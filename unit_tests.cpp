#include "gtest/gtest.h"
#include "Polygon_calculator.h"


TEST (Calculator, Test_get_value_from_string)
{
    EXPECT_EQ(Get_value("NotNumber"), -1);
    EXPECT_EQ(Get_value("627"), 627);
}

TEST (Calculator, Test_square)
{
    double x[4] = {0, 0, 4, 4};
    double y[4] = {0, 4, 4, 0};

    EXPECT_EQ((int)Polygon_square(4, x, y), 16);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

