#pragma once

#include "Useful/Geometry/Vec2f.hpp"

namespace uf {

    class Shape {
    protected:
        float angle;
        uf::vec2f position;
    public:
        Shape();

        uf::vec2f GetPosition() const { return position; }

        float GetRotation() const { return angle; }

        void SetPosition(const uf::vec2f &pos) { position = pos; }

        void SetPosition(const float x, const float y) {
            position.x = x;
            position.y = y;
        }

        void SetRotation(const float angle) { this->angle = angle; }

        virtual bool Intersect(Shape *shape) = 0;

        ~Shape() {}
    };

}