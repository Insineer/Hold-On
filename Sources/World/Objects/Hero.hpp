#pragma once

#include "Object.hpp"

class Hero : public Object {
public:
    Hero();

    virtual void Draw(sf::RenderTarget *target, vec2f targetCoord) const final;
    virtual void Update() final;
};


