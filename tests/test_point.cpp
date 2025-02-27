#include "../Core/Point.hpp"
#include <gtest/gtest.h>

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

TEST(PointTest, MagnitudeZero2D) {
  Point2D p({0.0, 0.0});
  EXPECT_EQ(p.magnitude(), 0.0);
}

TEST(PointTest, MagnitudeZero3D) {
  Point3D p({0.0, 0.0, 0.0});
  EXPECT_EQ(p.magnitude(), 0.0);
}

TEST(PointTest, MagnitudePositive) {
  Point2D p({120, 200});
  EXPECT_EQ(p.magnitude(), 233.23807579381202);
}

TEST(PointTest, MagnitudeNegative) {
  Point2D p({-120, -200});
  EXPECT_EQ(p.magnitude(), 233.23807579381202);
}

TEST(PointTest, MagnitudePositive3D) {
  Point3D p({120, 200, 500});
  EXPECT_EQ(p.magnitude(), 551.72456896534891);
}

TEST(PointTest, MagnitudeNegative3D) {
  Point3D p({-120, -200, -500});
  EXPECT_EQ(p.magnitude(), 551.72456896534891);
}
TEST(PointDivisionTest, DivisionByPositiveNumber) {
  std::array<double, 3> coords = {6.0, 9.0, 12.0};
  Point<double, 3> p(coords);
  Point<double, 3> result = p / 3.0;

  auto result_it = result.begin();
  EXPECT_DOUBLE_EQ(*result_it++, 2.0);
  EXPECT_DOUBLE_EQ(*result_it++, 3.0);
  EXPECT_DOUBLE_EQ(*result_it++, 4.0);
}

TEST(PointDivisionTest, DivisionByNegativeNumber) {
  std::array<double, 3> coords = {6.0, 9.0, 12.0};
  Point<double, 3> p(coords);
  Point<double, 3> result = p / -3.0;

  auto result_it = result.begin();
  EXPECT_DOUBLE_EQ(*result_it++, -2.0);
  EXPECT_DOUBLE_EQ(*result_it++, -3.0);
  EXPECT_DOUBLE_EQ(*result_it++, -4.0);
}

TEST(PointDivisionTest, DivisionByZero) {
  std::array<double, 3> coords = {6.0, 9.0, 12.0};
  Point<double, 3> p(coords);
  EXPECT_THROW(p / 0.0, std::runtime_error);
  EXPECT_THROW(p / 0.0, std::runtime_error);
}

TEST(TestReflection, TestReflection2D)
{
    std::array<double, 2> InputCoords = {2.0, 3.0};

    std::array<double, 2> ExpectedCoords = {3.0, 2.0};

    std::array<double, 2> Point1Coords = {0.0, 0.0};
    std::array<double, 2> Point2Coords = {1.0, 1.0}; 
    Point<double, 2> Input(InputCoords);
    Point<double, 2> Expected(ExpectedCoords);
    Point<double, 2> pt1(Point1Coords);
    Point<double, 2> pt2(Point2Coords);

    // Perform reflection
    Point<double, 2> result = Input.reflect(pt1, pt2);

    // Validate results
    EXPECT_DOUBLE_EQ(result[0], Expected[0]);
    EXPECT_DOUBLE_EQ(result[1], Expected[1]);
}

TEST(TestReflection, TestReflection3D) {
  std::array<double, 3> InputCoords = {3.0, 4.0, 5.0};
  std::array<double, 3> ExpectedCoords = {3.0, 4.0, -5.0};

  std::array<double, 3> PointCoords = {0.0, 0.0, 0.0};
  std::array<double, 3> NormalCoords = {0.0, 0.0, 1.0};

  Point<double, 3> Input(InputCoords);
  Point<double, 3> Expected(ExpectedCoords);

  Point<double, 3> pt(PointCoords);
  Point<double, 3> normal(NormalCoords);

  Point<double, 3> result = Input.reflect(pt, normal);

  EXPECT_DOUBLE_EQ(result[0], Expected[0]);
  EXPECT_DOUBLE_EQ(result[1], Expected[1]);
  EXPECT_DOUBLE_EQ(result[2], Expected[2]);
}

TEST(TestApproxEqual, TestPointForEqual2DPositive) {
  Point2D pt({0.0, 0.0});
  Point2D pt2({1e-10, 0.0});
  EXPECT_EQ(pt.approx_equal(pt2), true);

  pt = Point2D({100.0, 500.0});
  pt2 = Point2D({100.0001, 500.0005});
  EXPECT_EQ(pt.approx_equal(pt2,1e-2), true);
}

TEST(TestApproxEqual, TestPointForEqual2DNegative) {
  Point3D pt({0.0, 0.0});
  Point3D pt2({1e-3, 1e-4});
  EXPECT_EQ(pt.approx_equal(pt2), false);

  pt = Point3D({100.0, 500.0});
  pt2 = Point3D({100.0001, 5000.0});
  EXPECT_EQ(pt.approx_equal(pt2, 1e-3), false);
}

TEST(TestApproxEqual, TestPointForEqual3DPositive) {
  Point3D pt({0.0, 0.0, 0.0});
  Point3D pt2({1e-10, 0.0, 1e-10});
  EXPECT_EQ(pt.approx_equal(pt2), true);

  pt = Point3D({100.0, 500.0, 700.0});
  pt2 = Point3D({100.0001, 500.0005, 700.0002});
  EXPECT_EQ(pt.approx_equal(pt2, 1e-2), true);
}

TEST(TestApproxEqual, TestPointForEqual3DNegative) {
  Point3D pt({0.0, 0.0, 0.0});
  Point3D pt2({1e-7, 0.0, 0.5});
  EXPECT_EQ(pt.approx_equal(pt2), false);

  pt = Point3D({100.0, 500.0, 700});
  pt2 = Point3D({100.0001, 500.0005, 775});
  EXPECT_EQ(pt.approx_equal(pt2, 1e-3), false);
=======
TEST(PointTest, ProjectionOntoLine2D) {
  std::array<double, 2> p_coords = {3.0, 4.0};
  std::array<double, 2> line_p1_coords = {1.0, 1.0};
  std::array<double, 2> line_p2_coords = {5.0, 5.0};

  Point2D p(p_coords);
  Point2D line_p1(line_p1_coords);
  Point2D line_p2(line_p2_coords);

  Point2D projected = p.project_onto_line(line_p1, line_p2);

  std::array<double, 2> expected_coords = {3.5, 3.5}; // Expected projection
  EXPECT_NEAR(projected[0], expected_coords[0], 1e-9);
  EXPECT_NEAR(projected[1], expected_coords[1], 1e-9);
}

TEST(PointTest, ProjectionOntoLine3D) {
  std::array<double, 3> p_coords = {2.0, 3.0, 4.0};
  std::array<double, 3> line_p1_coords = {0.0, 0.0, 0.0};
  std::array<double, 3> line_p2_coords = {1.0, 1.0, 1.0};

  Point3D p(p_coords);
  Point3D line_p1(line_p1_coords);
  Point3D line_p2(line_p2_coords);

  Point3D projected = p.project_onto_line(line_p1, line_p2);

  std::array<double, 3> expected_coords = {3.0, 3.0, 3.0}; // Expected projection
  EXPECT_NEAR(projected[0], expected_coords[0], 1e-9);
  EXPECT_NEAR(projected[1], expected_coords[1], 1e-9);
  EXPECT_NEAR(projected[2], expected_coords[2], 1e-9);
}

TEST(PointTest, ProjectionOntoDegenerateLine) {
  std::array<double, 2> p_coords = {3.0, 4.0};
  std::array<double, 2> line_p1_coords = {2.0, 2.0};
  std::array<double, 2> line_p2_coords = {2.0, 2.0}; // Degenerate case (same points)

  Point2D p(p_coords);
  Point2D line_p1(line_p1_coords);
  Point2D line_p2(line_p2_coords);

  EXPECT_THROW(p.project_onto_line(line_p1, line_p2), std::runtime_error);
}