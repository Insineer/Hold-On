#pragma once

#include "Useful/Geometry/Vec2f.hpp"
#include "Shape.hpp"

namespace uf {

    class Rectangle : public Shape {
    private:
        uf::vec2f size;
    public:
        Rectangle(const uf::vec2f &size) : size(size) {}

        bool Intersect(Shape *shape);

        uf::vec2f GetSize() const { return size; }
    };

}