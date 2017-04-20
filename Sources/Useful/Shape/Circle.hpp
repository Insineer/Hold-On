#pragma once

#include "Useful/Shape/Shape.hpp"

class Circle : public Shape {
    float radius;
public:
    Circle(float radius) : radius(radius) {}

    float GetRadius() const { return radius; }
    bool Intersect(Shape *shape);
};

