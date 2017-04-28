#pragma once

#include "Shape.hpp"

namespace uf {

    class Circle : public Shape {
    private:
        float radius;

    public:
        explicit Circle(const float radius = 0) : radius(radius) {}

        bool Intersect(Shape *shape);

        void SetRadius(const float radius) { this->radius = radius; }
        float GetRadius() const { return radius; }
    };

}

