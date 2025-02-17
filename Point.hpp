#ifndef POINT_HPP
#define POINT_HPP

#include <array>
#include <iostream>

template <typename T, std::size_t Dim>
class Point {
public:
    // Constructor to initialize the point
    Point(const std::array<T, Dim>& coordinates) : coordinates_(coordinates) {}

    // Function to translate the point by another point or vector
    void translate(const Point<T, Dim>& translation) {
        for (std::size_t i = 0; i < Dim; ++i) {
            coordinates_[i] += translation.coordinates_[i];
        }
    }

    // Static function to interpolate between two points
    static Point<T, Dim> lerp(const Point<T, Dim>& p1, const Point<T, Dim>& p2, T t) {
        std::array<T, Dim> result;
        for (std::size_t i = 0; i < Dim; ++i) {
            result[i] = (1 - t) * p1.coordinates_[i] + t * p2.coordinates_[i];
        }
        return Point<T, Dim>(result);
    }

    // Function to print the point coordinates
    void print() const {
        for (const auto& coord : coordinates_) {
            std::cout << coord << " ";
        }
        std::cout << std::endl;
    }

    // Get coordinates for testing
    const std::array<T, Dim>& getCoordinates() const {
        return coordinates_;
    }

private:
    std::array<T, Dim> coordinates_;
};

#endif // POINT_HPP
