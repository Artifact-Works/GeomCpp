#include <iostream>
#include <gtest/gtest.h>
#include "Point.hpp"
#include "./Point_traits.hpp"

using namespace GeomCPP;
TEST(PointDivisionTest, DivisionByPositiveNumber) 
{
    std::array<double, 3> coords= {6.0,9.0,12.0};
    Point<double, 3> p(coords);
    Point<double, 3> result = p /3.0; 

    auto result_it = result.begin();
    EXPECT_DOUBLE_EQ(*result_it++,2.0); 
    EXPECT_DOUBLE_EQ(*result_it++,3.0); 
    EXPECT_DOUBLE_EQ(*result_it++,4.0);
}

TEST(PointDivisionTest, DivisionByNegativeNumber) 
{
    std::array<double, 3> coords= {6.0,9.0,12.0};
    Point<double, 3> p(coords); 
    Point<double, 3> result = p /-3.0; 

    auto result_it = result.begin();
    EXPECT_DOUBLE_EQ(*result_it++,-2.0); 
    EXPECT_DOUBLE_EQ(*result_it++,-3.0); 
    EXPECT_DOUBLE_EQ(*result_it++,-4.0);
}

TEST(PointDivisionTest, DivisionByZero)
{
    std::array<double, 3> coords= {6.0,9.0,12.0};
    Point<double, 3> p(coords);
    EXPECT_THROW(p / 0.0, std::runtime_error);
}
