#include <iostream>
#include <gtest/gtest.h>
#include "Point.hpp"
#include "./Point_traits.hpp"

using namespace GeomCPP; 

TEST(TestReflection, TestReflection2D)
{
    std::array<double,2> InputCoords = {2.0,3.0};
    std::array<double,2> ExpectedCoords = {3.0,2.0};

    std::array<double,2> Point1Coords = {0.0,0.0};
    std::array<double,2> Point2Coords = {.0,1.0};

    Point<double,2> Input(InputCoords);
    Point<double,2> Expected(ExpectedCoords);

    Point<double,2> pt1(Point1Coords);
    Point<double,2> pt2(Point2Coords);

    Point<double,2> result = Input.reflect(pt1,pt2);

    EXPECT_DOUBLE_EQ(result[0],Expected[0]);
    EXPECT_DOUBLE_EQ(result[1],Expected[1]);

}   

TEST(TestReflection, TestReflection3D)
{
    std::array<double,3> InputCoords = {3.0,4.0,5.0};
    std::array<double,3> ExpectedCoords = {3.0,4.0,-5.0};

    std::array<double,3> PointCoords = {0.0,0.0,0.0};
    std::array<double,3> NormalCoords = {0.0,0.0,1.0};

    Point<double,3> Input(InputCoords);
    Point<double,3> Expected(ExpectedCoords);

    Point<double,3> pt(PointCoords);
    Point<double,3> normal(NormalCoords);

    Point<double,3> result = Input.reflect(pt,normal);

    EXPECT_DOUBLE_EQ(result[0],Expected[0]);
    EXPECT_DOUBLE_EQ(result[1],Expected[1]);
    EXPECT_DOUBLE_EQ(result[2],Expected[2]);

}