#include <gtest/gtest.h>
#include "../Core/Point.hpp"

using namespace GeomCPP;

using Point2D = Point<double, 2>;
using Point3D = Point<double, 3>;

TEST(PointTest, ConstructorAndCoordinates) {
    std::array<double, 2> coords = {1.0, 2.0};
    Point2D p(coords);
    
    EXPECT_EQ(p.get_coordinates(), coords);
}

TEST(PointTest, AdditionOperator) {
    std::array<double, 2> coords1 = {1.0, 2.0};
    std::array<double, 2> coords2 = {3.0, 4.0};
    
    Point2D p1(coords1);
    Point2D p2(coords2);
    Point2D result = p1 + p2;

    std::array<double, 2> expected_coords = {4.0, 6.0};
    EXPECT_EQ(result.get_coordinates(), expected_coords);
}

TEST(PointTest, SubtractionOperator) {
    std::array<double, 2> coords1 = {5.0, 6.0};
    std::array<double, 2> coords2 = {3.0, 2.0};
    
    Point2D p1(coords1);
    Point2D p2(coords2);
    Point2D result = p1 - p2;

    std::array<double, 2> expected_coords = {2.0, 4.0};
    EXPECT_EQ(result.get_coordinates(), expected_coords);
}

TEST(PointTest, EqualityOperator) {
    std::array<double, 2> coords1 = {1.0, 2.0};
    std::array<double, 2> coords2 = {1.0, 2.0};
    std::array<double, 2> coords3 = {3.0, 4.0};
    
    Point2D p1(coords1);
    Point2D p2(coords2);
    Point2D p3(coords3);

    EXPECT_TRUE(p1 == p2);  
    EXPECT_FALSE(p1 == p3); 
}

TEST(PointTest, Distance) {
    std::array<double, 2> coords1 = {1.0, 2.0};
    std::array<double, 2> coords2 = {4.0, 6.0};
    
    Point2D p1(coords1);
    Point2D p2(coords2);
    
    double expected_distance = std::sqrt(3.0 * 3.0 + 4.0 * 4.0); 
    EXPECT_NEAR(p1.distance(p2), expected_distance, 1e-9);
}

TEST(PointTest, DotProduct) {
    std::array<double, 2> coords1 = {1.0, 2.0};
    std::array<double, 2> coords2 = {3.0, 4.0};
    
    Point2D p1(coords1);
    Point2D p2(coords2);
    
    double expected_dot = 1.0 * 3.0 + 2.0 * 4.0; 
    EXPECT_EQ(p1.dot(p2), expected_dot);
}

TEST(PointTest, Scale) {
    std::array<double, 2> coords = {2.0, 3.0};
    
    Point2D p(coords);
    p.scale(2.0);
    
    std::array<double, 2> expected_coords = {4.0, 6.0}; 
    EXPECT_EQ(p.get_coordinates(), expected_coords);
}

TEST(PointTest, Collinearity) {
    std::array<double, 2> coords1 = {0.0, 0.0};
    std::array<double, 2> coords2 = {1.0, 1.0};
    std::array<double, 2> coords3 = {2.0, 2.0};
    
    Point2D p1(coords1);
    Point2D p2(coords2);
    Point2D p3(coords3);
    
    EXPECT_TRUE(Point2D::collinear(p1, p2, p3));
    
    coords3 = {2.0, 3.0};
    Point2D p4(coords3);
    
    EXPECT_FALSE(Point2D::collinear(p1, p2, p4));
}

TEST(PointTest, GetDimensions) {
    std::array<double, 2> coords = {1.0, 2.0};
    Point2D p(coords);
    
    EXPECT_EQ(p.get_dimensions(), 2);
}

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
    EXPECT_THROW(p / 0.0 ,std::runtime_error);
    EXPECT_THROW(p / 0.0, std::runtime_error);
}

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
                     


