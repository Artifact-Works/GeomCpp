#pragma once
#include <array>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <concepts>
#include "./Point_traits.hpp"
    

namespace GeomCPP {


template <typename T, size_t Dim> 
requires point_numeric<T> 
class Point {
public:
    using point = Point<T, Dim>;
    using iterator = typename std::array<T, Dim>::iterator;
    using const_iterator = typename std::array<T, Dim>::const_iterator;

private:
    std::array<T, Dim> coordinates;
    size_t dimensions;

public:
    std::array<T, Dim> get_coordinates() const { return coordinates; }
    iterator begin() { return coordinates.begin(); }
    iterator end() { return coordinates.end(); }
    const_iterator begin() const { return coordinates.begin(); }
    const_iterator end() const { return coordinates.end(); }
    const_iterator cbegin() const { return coordinates.cbegin(); }
    const_iterator cend() const { return coordinates.cend(); }
    
    [[nodiscard]] inline static constexpr size_t get_dimensions() { return Dim; };
    
    Point(std::array<T, Dim> init) : coordinates(init), dimensions(init.size()) {}

    point operator+(const point &other) const { 
        point result = *this; 
        for (size_t i = 0; i < Dim; ++i) 
            result.coordinates[i] += other.coordinates[i]; 
        return result; 
    }

    point operator-(const point &other) const { 
        point result = *this; 
        for (size_t i = 0; i < Dim; ++i) 
            result.coordinates[i] -= other.coordinates[i]; 
        return result; 
    }

    T operator[](size_t index) const { 
        return coordinates.at(index); // Use .at() for bounds checking 
    }

    point operator/(const T scalar) const 
    {
        if (scalar==0) throw std::runtime_error("Division by zero");

        point result = *this;
        for (size_t counter=0; counter<Dim; ++counter) result.coordinates[counter]= coordinates[counter]/scalar;

        return result ;
    }

    template <valid_scalar ScalarType>
    void scale(ScalarType scalar)
    {
        for (auto &coord : coordinates)
            coord *= scalar;
    }

    point &operator=(const point &other) { 
        coordinates = other.coordinates; 
        return *this; 
    }

    T dot(const point &other) const { 
        T result = 0; 
        for (size_t i = 0; i < Dim; ++i) 
            result += coordinates[i] * other.coordinates[i]; 
        return result; 
    }

    bool operator==(const point &other) const { 
        for (size_t i = 0; i < Dim; ++i) { 
            if (std::abs(coordinates[i] - other.coordinates[i]) > 1e-9) 
                return false; 
        } 
        return true; 
    }

    T distance(const point &other) const { 
        T dist = 0; 
        for (size_t i = 0; i < Dim; ++i) 
            dist += (coordinates[i] - other.coordinates[i]) * (coordinates[i] - other.coordinates[i]); 
        return std::sqrt(dist); 
    }

    template <valid_scalar ScalarType> 
    void scale(ScalarType scalar) { 
        for (auto &coord : coordinates) 
            coord *= scalar; 
    }

    void print() const { 
        std::cout << "("; 
        for (size_t i = 0; i < Dim; ++i) { 
            std::cout << coordinates[i]; 
            if (i < Dim - 1) 
                std::cout << ", "; 
        } 
        std::cout << ")\n"; 
    }

    template <typename P1, typename P2, typename P3> 
    requires same_length_points<P1, P2, P3> 
    static bool collinear(const P1 &p1, const P2 &p2, const P3 &p3) { 
        auto determinant = (p2[0] - p1[0]) * (p3[1] - p1[1]) - (p2[1] - p1[1]) * (p3[0] - p1[0]); 
        return std::abs(determinant) < 1e-9; 
    }
};

} // namespace GeomCPP
