#pragma once

#include "Object.hpp"

namespace uf {
    class Circle;
}

class Hero : public Object {
    uf::Circle *shapeCircle;

public:
    Hero();

    virtual void Draw(sf::RenderTarget *target, uf::vec2f targetCoord) const final;
    virtual void Update() final;
};


