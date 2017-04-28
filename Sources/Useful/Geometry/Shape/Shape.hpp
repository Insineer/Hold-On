#pragma once

#include "Useful/Geometry/Vec2f.hpp"

class Shape {
protected:
    float angle; //Has to be between -180 and 180
    uf::vec2f position;
public:
    Shape();

    uf::vec2f GetPosition() const { return position; }
    float GetRotation() const { return angle; }

    void SetPosition(const uf::vec2f &pos) { position = pos; }
    void SetPosition(const float x, const float y) { position.x = x; position.y = y; }
    void SetRotation(const float ang) { angle = ang; }

    virtual bool Intersect(Shape *shape) = 0;

    ~Shape() {}
};