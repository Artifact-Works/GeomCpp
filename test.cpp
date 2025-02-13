#include <iostream>
#include "./GeomCpp/Core/Point.hpp"
#include "./GeomCpp/Visualizer/Visualizer.hpp"

namespace gp = GeomCPP;

int main()
{
    // Create 2D points
    gp::Point<double, 2> p1 = {{100.1, 200.2}};
    gp::Point<double, 2> p2 = {{400.0, 500.0}};

    gp::Point<double, 2> p3 = p1 + p2;
    std::cout << "Sum: ";
    p3.print();

    double dot_result = p1.dot(p2);
    std::cout << "Dot product: " << dot_result << "\n";

    double dist = p1.distance(p2);
    std::cout << "Distance: " << dist << "\n";

    std::cout << "Scaling p1 by 1.4: \n";
    p1.scale(1.4);
    p1.print();

    using Point_2D = gp::Point<double, 2>;

    std::cout << "Collinear test: "
              << Point_2D::collinear(Point_2D({1.0, 1}), Point_2D({2.0, 2.0}), Point_2D({3.0, 3.0}))
              << "\n"; // Expected output: 1 (true)

    std::cout << "Coordinates of p2: ";
    for (const auto &coord : p2)
    {
        std::cout << coord << " ";
    }
    std::cout << std::endl;

    // Linear interpolation (lerp) example
    double t = 0.5;
    gp::Point<double, 2> p_lerp = gp::Point<double, 2>::lerp(p1, p2, t);
    std::cout << "Lerp result: ";
    p_lerp.print();

    gp::Visualizer vis;

    vis.addPoint(p1);
    vis.addPoint(p2);
    vis.addPoint(p3);
    vis.addPoint(p_lerp);
    vis.run();
    return 0;
}
