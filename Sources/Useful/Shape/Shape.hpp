#pragma once

#include "Useful/Vec2f.hpp"

class Shape {
protected:
    float angle; //Has to be between -180 and 180
    vec2f position;
public:
    vec2f GetPosition() const { return position; }
    float GetRotation() const { return angle; }

    void SetPosition(const vec2f &pos) { position = pos; }
    void SetRotation(const float ang) { angle = ang; }

    virtual bool Intersect(Shape *shape) = 0;

    ~Shape() {}
};