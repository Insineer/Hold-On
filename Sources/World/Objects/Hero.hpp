#pragma once

#include "Object.hpp"

namespace sf {
    class CircleShape;
}

class Hero : public Object {
    float radius;
public:
    Hero();

    virtual void Draw(sf::RenderTarget *target, vec2f targetCoord) const final;
    virtual void Update() final;
};


