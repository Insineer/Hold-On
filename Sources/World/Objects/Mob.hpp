#pragma once

#include "Object.hpp"

namespace sf {
    class CircleShape;
}

namespace uf {
    class Circle;
}

class Mob : public Object {
private:
    float velocity;
    uf::Circle *shapeCircle;

    uf::vec2f getShift(const uf::vec2f &diff);
public:
    Mob();

    virtual void Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const final;
    virtual void Update() final;
};