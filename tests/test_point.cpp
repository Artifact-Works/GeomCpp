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

TEST(PointTest,MagnitudeZero2D){
	Point2D p({0.0,0.0});
	EXPECT_EQ(p.magnitude(),0.0);
}

TEST(PointTest,MagnitudeZero3D){
	Point3D p({0.0,0.0,0.0});
	EXPECT_EQ(p.magnitude(),0.0);
}

TEST(PointTest,MagnitudePositive){
	Point2D p({120,200});
	EXPECT_EQ(p.magnitude(),233.23807579381202);
}

TEST(PointTest,MagnitudeNegative){
	Point2D p({-120,-200});
	EXPECT_EQ(p.magnitude(),233.23807579381202);
}

TEST(PointTest,MagnitudePositive3D){
	Point3D p({120,200,500});
	EXPECT_EQ(p.magnitude(),551.72456896534891);
}

TEST(PointTest,MagnitudeNegative3D){
	Point3D p({-120,-200,-500});
	EXPECT_EQ(p.magnitude(),551.72456896534891);
}

