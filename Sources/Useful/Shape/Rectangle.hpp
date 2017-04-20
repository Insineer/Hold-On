#pragma once

#include "Useful/Vec2f.hpp"
#include "Shape.hpp"

class Rectangle : public Shape{
private:
    vec2f size;
public:
    Rectangle(const vec2f &size) : size(size) {}

    vec2f GetSize() const { return size; }
    bool Intersect(Shape *shape);
};